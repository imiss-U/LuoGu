#include <iostream>
#include <vector>
using namespace std;
class Solution{
	public:
		int findRight(vector<int>& nums, int target){
			int left = 0, right = nums.size() - 1, res = -2;
			while(left <= right){
				int mid = left + ((right - left) >> 1);
				if (nums[mid] <= target){
					left = mid + 1;
					res = left;
				}
				else if(nums[mid] > target)
					right = mid - 1;
			}
			return res;
		}
		int findLeft(vector<int>& nums, int target){
			int left = 0, right = nums.size() - 1, res = -2;
			while(left <= right){
				int mid = left + ((right - left) >> 1);
				if (nums[mid] >= target){
					right = mid - 1;
					res = right;
				}
				else if (nums[mid] < target)
					left = mid + 1;
			}
			return res;
		}
		vector<int> searchRange(vector<int>& nums, int target){
			int border1 = findLeft(nums, target);
			int border2 = findRight(nums, target);
			if (border1 == -2 || border2 == -2)
				return {-1, -1};
			if (border2 - border1 > 1)
				return {border1 + 1, border2 - 1};
			return {-1, -1};
		}
};
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int target, tmp;
	cin >> target;
	vector<int> nums;
	while(cin >> tmp)
		nums.push_back(tmp);
	Solution sol;
	vector<int> res(sol.searchRange(nums, target));
	for (auto x : res)
		cout << x << " ";
	return 0;
}
