#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Heap {
public:
    vector<int> num;
    void push_up(int i) {
        while (i > 0) {
            int parent = (i - 1) / 2;
            if (num[parent] <= num[i])
                break;
            else
                swap(num[parent], num[i]);
            i = parent;
        }
    }

    void push_down(int i) {
        while (i < num.size()) {
            int left = i * 2 + 1, right = i * 2 + 2;
            if (left >= num.size())
                break;
            int min_child = left;
            if (right < num.size() && num[right] < num[left])
                min_child = right;
            if (num[i] > num[min_child])
                swap(num[i], num[min_child]);
            else
                break;
            i = min_child;
        }
    }

    void push(int x) {
        num.push_back(x);
        push_up(num.size() - 1);
    }

    void pop() {
        swap(num[0], num[num.size() - 1]);
        num.pop_back();
        push_down(0);
    }

    int top() {
        return num[0];
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    vector<int> num;
    int n;
    cin >> n;
    Heap heap;
    for (int i = 0; i < n; i++) {
        int op;
        cin >> op;
        if (op == 1) {
            int x;
            cin >> x;
            heap.push(x);
        }
        else if (op == 2) {
            cout << heap.top() << "\n";
        }
        else {
            heap.pop();
        }
    }
    return 0;
}