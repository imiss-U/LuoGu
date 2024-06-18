#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution{
	public:
		vector<string> res;
		void buildTree(TreeNode *mytree){
			int str;
			while (cin >> str){
				if (str >=0 && str <= 9)
					mytree->val = str;
				else
					mytree = nullptr;
				buildTree(mytree->left);
				buildTree(mytree->right);
			}
		}
		void dfs(TreeNode *mytree){
			if (mytree){
				res.push_back(to_string(mytree->val));
			}
			dfs(mytree->left);
			dfs(mytree->right);
		}
		vector<string> binaryTreePaths(TreeNode* root){
			buildTree(root);
			dfs(root);
			return res;
		}
};
int main(){
	Solution sol;
	TreeNode* root;
	sol.binaryTreePaths(root);
	for (auto &x : sol.res){
		cout << x << " ";
	}
	return 0;
}
