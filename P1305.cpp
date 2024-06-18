// # 从题解得到启发  然后找的二叉树的查找函数的轮子
// # 得到一个处理二叉树建立的小技巧：当输入序列中含有树的构造方式时 可以使用Find函数找到目标节点再继续建树(后续节点必定存在--见B3642)
#include <iostream>
using namespace std;
struct TreeNode {
	char data;
	TreeNode* left, * right;
};
TreeNode* node = nullptr;
TreeNode* Find(char ch, TreeNode*& node) {
	if (!node)
		return nullptr;
	else {
		if (node->data == ch)
			return node;
		else {
			TreeNode* temp = Find(ch, node->left);
			if (temp == nullptr)
				temp = Find(ch, node->right);
			return temp;
		}
	}
}
void Insert(char root, char left, char right) {
	TreeNode* temp = Find(root, node);
	if (left != '*') {
		temp->left = new TreeNode();
		temp->left->data = left;
	}
	else
		temp->left = nullptr;
	if (right != '*') {
		temp->right = new TreeNode();
		temp->right->data = right;
	}
	else
		temp->right = nullptr;
}
void PreTravel(TreeNode*& node) {
	if (node != nullptr) {
		cout << node->data;
		PreTravel(node->left);
		PreTravel(node->right);
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int N;
	cin >> N;
	char root, l, r;
	cin >> root >> l >> r;
	node = new TreeNode();
	node->data = root;
	if (l != '*') {
		node->left = new TreeNode();
		node->left->data = l;
	}
	else
		node->left = nullptr;
	if (r != '*') {
		node->right = new TreeNode();
		node->right->data = r;
	}
	else
		node->right = nullptr;
	for (int i = 1; i < N; i++) {
		char root, l, r;
		cin >> root >> l >> r;
		Insert(root, l, r);
	}
	PreTravel(node);
	return 0;
}
