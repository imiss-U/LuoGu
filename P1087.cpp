// # 第一次提交50pts 一半测试点没过 后来看了讨论区得到启发  知道字符串中可能有空格和换行 改了一下Type函数 第二遍AC了
#include <iostream>
#include <string>
using namespace std;
struct TreeNode{
	string str;
	TreeNode *left, *right;
};
char Type(string &str) {
	if(str[0] == '0') {
		unsigned int k = 1;
		while(k < str.size()) {
			if (str[k++] == '1')
				return 'F';
		}
		return 'B';
	}
	else {
		unsigned int k = 1;
		while(k < str.size()) {
			if (str[k++] == '0')
				return 'F';
		}
		return 'I';
	}
}
TreeNode* buildTree(string str, TreeNode *node) {
	if (str.size() == 1) {
		node = new TreeNode();
		node->str = str;
		node->left = nullptr;
		node->right = nullptr;
		return node;
	}
	node = new TreeNode();
	node->str = str;
	node->left = buildTree(str.substr(0, str.size() / 2), node->left);
	node->right = buildTree(str.substr(str.size() / 2, str.size() / 2), node->right);
	return node;
}
void PostTravel(TreeNode *&node){
	if (node != nullptr) {
		PostTravel(node->left);
		PostTravel(node->right);
		cout << Type(node->str);
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int N;
	cin >> N;
	string str;
	cin >> str;
	TreeNode *node = buildTree(str, node);
	PostTravel(node);
	return 0;
}
