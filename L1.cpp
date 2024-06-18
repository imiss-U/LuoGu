#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); i++)
            m.insert({nums[i], i});
        for (int i = 0; i < nums.size(); i++) {
            auto it = m.find(target - nums[i]);
            if (it != m.end() && it->second != i)
                return {i, it->second};
        }
        return {};
    }
};
int main() {
    Solution sol;
    vector<int> nums = /*{2, 7, 11, 15}*/{3,2,4};
    int target = /*9*/6;
    vector<int> output = sol.twoSum(nums, target);
    for (auto i : output)
        cout << i << " ";
    return 0;
}