#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
	public:
		vector<vector<int>> res;
		vector<int> path;
		void dfs(vector<int>& nums, vector<bool>& flag) {
			if (path.size() == nums.size()) {
				res.push_back(path);
				return;
			}
			for (int i = 0; i < nums.size(); i++) {
				if (i > 0 && nums[i] == nums[i - 1] && flag[i - 1] == false)
					continue;
				if (flag[i] == false) {
					flag[i] = true;
					path.push_back(nums[i]);
					dfs(nums, flag);
					path.pop_back();
					flag[i] = false;
				}
			}
		}
		vector<vector<int>> permuteUnique(vector<int>& nums) {
			vector<bool> flag(nums.size(), false);
			sort(nums.begin(), nums.end());
			dfs(nums, flag);
			return res;
		}
};
int main() {
	vector<int> nums;
	int tmp;
	while(cin >> tmp)
		nums.push_back(tmp);
	Solution sol;
	sol.permuteUnique(nums);
	for (auto &x : sol.res) {
		for (auto y : x)
			cout << y << " ";
		cout << "\n";
	}
	return 0;
}
