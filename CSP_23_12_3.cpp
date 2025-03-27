#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
using namespace std;
struct Node {
    int id;
    int weight;
    vector<Node*> children;
    bool chosed = true;
    ~Node() {
        for (auto& it : children)
            delete it;
        this->children.clear();
    }
};

Node* home = new Node();
unordered_map<int, Node*> umap;
long long total = 0;


bool Empty(Node *& root, int goal) {
    if (root == nullptr && root->id == goal)
        return true;
    for (auto &it : root->children)
        if (it->chosed)
            return false;
    return true;
}
void f(Node *&root) {
    if (root->chosed == false)
        root->chosed = true;
    for (auto &it : root->children)
        f(it);
}

void output(Node*& root) {
    cout << root->id << " : " << root->weight << "\n";
    for (auto& it : root->children)
        output(it);
}

long long treeWeight(Node*& root) {
    if (root == nullptr || !root->chosed)
        return 0;
    long long sum = root->weight;
    for (auto& it : root->children)
        if (it->chosed)
            sum += treeWeight(it);
    return sum;
}

Node*& seekNode(int id, Node*& root) {
    static Node* ro = nullptr;
    if (root->id == id && root->chosed == true)
        return root;
    for (auto& it : root->children) {
        Node*& tmp = seekNode(id, it);
        if (tmp != nullptr)
            return tmp;
    }
    return ro;
}

void deleteTree(Node*& root) {
    if (root == nullptr)
        return;
    for (auto& it : root->children)
        deleteTree(it);
    delete root;
    root = nullptr;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    home->id = 1;
    cin >> home->weight;
    total += home->weight;
    umap.insert({home->id, home});
    for (int i = 2; i <= n; i++) {
        Node* root = new Node();
        cin >> root->weight;
        total += root->weight;
        root->id = i;
        umap.insert({root->id, root});
    }
    for (int i = 2; i <= n; i++) {
        int target;
        cin >> target;
        Node* parent = umap[target];
        Node* child = umap[i];
        parent->children.push_back(child);
    }
    for (int i = 0; i < m; i++) {
        int goal;
        cin >> goal;
        Node*& temp = seekNode(goal, home);
        int min, num;
        do {
            min = 10000000;
            for (int j = 0; j < umap.size(); j++) {
                int tmp = abs(total - treeWeight(umap[j + 1]) * 2);
                if (tmp < min) {
                    min = tmp;
                    num = j + 1;
                }
            }
            cout << num << " ";
            if (num != goal) {
                total -= treeWeight(umap[num]);
                Node*& parent = seekNode(num, home);
                // deleteTree(parent);
                parent->chosed = false;
                umap.erase(num);
            }
        }
        while (/*Empty(temp, goal) == false  这里面有问题*/true);
        cout << "\n";
        f(home);
    }
    return 0;
}