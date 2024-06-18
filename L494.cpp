#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int findTargetSumWays(vector<int> &nums, int target)
    {
        int sum = 0;
        for (int x : nums)
        {
            sum += x;
        }
        int V = (sum + target) / 2, N = nums.size();
        if (target > sum)
            return 0;
        if (target < 0 - sum)
            return 0;
        if ((sum + target) % 2 == 1)
            return 0;
        vector<int> res(20010, 0);
        res[0] = 1;
        for (int i = 0; i < N; i++)
        {
            for (int j = V; j >= nums[i]; j--)
            {
                res[j] += res[j - nums[i]];
            }
        }
        return res[V];
    }
};
int main()
{
    vector<int> myvec = {1, 1, 1, 1, 1};
    Solution sol;
    cout << sol.findTargetSumWays(myvec, 5);
    return 0;
}