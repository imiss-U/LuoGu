#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        int N = coins.size(), V = amount;
        vector<int> res(amount + 1, 10000000);
        res[0] = 0;
        for (int i = 0; i < N; i++)
        {
            for (int j = coins[i]; j <= V; j++)
            {
                res[j] = min(res[j], res[j - coins[i]] + 1);
            }
        }
        if (res[V] == 0)
            return -1;
        return res[V];
    }
};
int main()
{
    vector<int> coins = {1, 2, 5};
    int amount = 11;
    Solution sol;
    cout << sol.coinChange(coins, amount);
    return 0;
}