#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
class Solution{
	public:
		vector<vector<int>> res;
		vector<int> path;
		void dfs(vector<int>& nums, int startindex){
			if (path.size() >= 2)
				res.push_back(path);
			unordered_set<int> myset;
			for (int i = startindex; i < nums.size(); i++){
				if ((!path.empty() && nums[i] < path.back()) || myset.find(nums[i]) != myset.end())
					continue;
				myset.insert(nums[i]);
				path.push_back(nums[i]);
				dfs(nums, i + 1);
				path.pop_back();
			}
		}
		vector<vector<int>> findSubsequences(vector<int>& nums){
			dfs(nums, 0);
			return res;
		}
};
int main(){
	int tmp;
	Solution sol;
	vector<int> nums;
	while(cin >> tmp)
		nums.push_back(tmp);
	sol.findSubsequences(nums);
	for (auto &x : sol.res){
		for (auto y : x){
			cout << y << " ";
		}
		cout << "\n";
	}
	return 0;
}
