#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int lastStoneWeightII(vector<int> &stones)
    {
        int sum = 0;
        for (int x : stones)
        {
            sum += x;
        }
        int V = sum / 2;
        int N = stones.size();
        vector<int> res(3010, 0);
        for (int i = 0; i < N; i++)
        {
            for (int j = V; j >= stones[i]; j--)
            {
                res[j] = max(res[j], res[j - stones[i]] + stones[i]);
            }
        }
        return abs(sum - 2 * res[V]);
    }
};
int main()
{
    Solution sol;
    vector<int> myvec = {31, 26, 33, 21, 40};
    cout << sol.lastStoneWeightII(myvec);
    return 0;
}