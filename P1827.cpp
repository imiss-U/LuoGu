#include <iostream>
#include <algorithm>
using namespace std;
struct BTNode {
	char data;
	BTNode* left = nullptr, * right = nullptr;
};
BTNode* makeTree(char* mid, char* pre, int size) {
	if (size <= 0)
		return nullptr;
	BTNode* root = new BTNode();
	root->data = pre[0];
	int pos = find(mid, mid + size, pre[0]) - mid;
	root->left = makeTree(mid, pre + 1, pos);
	root->right = makeTree(mid + pos + 1, pre + pos + 1, size - pos - 1);
	return root;
}
void postTravel(BTNode* root) {
	if (root != nullptr) {
		postTravel(root->left);
		postTravel(root->right);
		cout << root->data;
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	char mid[50], pre[50];
	cin >> mid >> pre;
	int len = 0;
	for (auto ch : mid)
		if (ch != '\0')
			len++;
		else
			break;
	BTNode* root = makeTree(mid, pre, len);
	postTravel(root);
	return 0;
}
