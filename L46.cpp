#include <iostream>
#include <vector>
using namespace std;
class Solution{
	public:
		vector<vector<int>> res;
		vector<int> path;
		void dfs(vector<int>& nums, vector<bool>& flag){
			if (path.size() == nums.size()){
				res.push_back(path);
				return;
			}
			for (int i = 0; i < nums.size(); i++){
				if (flag[i] == true)
					continue;
				flag[i] = true;
				path.push_back(nums[i]);
				dfs(nums, flag);
				path.pop_back();
				flag[i] = false;
			}
		}
		vector<vector<int>> permute(vector<int>& nums){
			vector<bool> flag(nums.size(), false);
			dfs(nums, flag);
			return res;
		}
};
int main(){
	vector<int> tmp;
	int temp;
	while(cin >> temp)
		tmp.push_back(temp);
	Solution sol;
	sol.permute(tmp);
	for (auto &x : sol.res){
		for (auto y : x)
			cout << y << " ";
		cout << "\n";
	}
	return 0;
}
