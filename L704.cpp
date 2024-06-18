#include <iostream>
#include <vector>
using namespace std;
class Solution{
	public:
		int search(vector<int>& nums, int target){
			int left = 0, right = nums.size() - 1;
			while(left <= right){
				int mid = left + ((right - left) >> 1);
				if (nums[mid] == target)
					return mid;
				else if (nums[mid] < target)
					left = mid + 1;
				else if (nums[mid] > target)
					right = mid - 1;
			}
			return -1;
		}
};
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	vector<int> nums;
	int tmp, target;
	cin >> target;
	while(cin >> tmp)
		nums.push_back(tmp);
	Solution sol;
	int res = sol.search(nums, target);
	cout << res;
	return 0;
}
