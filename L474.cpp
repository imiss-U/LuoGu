// ! 有问题！！！！
#include <iostream>
#include <vector>
using namespace std;
int res[110][605][105];
class Solution
{
public:
    int findMaxForm(vector<string> &strs, int m, int n)
    {
        int V1 = m, V2 = n, N = strs.size();
        vector<int> cost1(102, 0), cost2(102, 0);
        for (int x = 0; x < N; x++)
        {
            for (int y = 0; strs[x][y]; y++)
            {
                if (strs[x][y] == '0')
                    cost1[x]++;
                if (strs[x][y] == '1')
                    cost2[x]++;
            }
        }
        // vector<vector<int>> res(605, vector<int>(105));
        for (int i = 0; i < N; i++)
        {
            for (int j = V1, k = V2; j >= cost1[i] && k >= cost2[i]; j--, k--)
            {
                res[i][j][k] = max(res[i][j][k], res[i - 1][j - cost1[i]][k - cost2[i]] + 1);
            }
        }
        // for (int i = N - 1, j = V1, k = V2; res[j][k] && i >= 0; i--)
        // {
        //     if (res[j][k] == res[j - cost1[i]][k - cost2[i]] + 1)
        //     {
        //         cout << i << " ";
        //         j--;
        //     }
        // }
        // for (int j = V1, k = V2; j >= cost1[i] && k >= cost2[i]; j--, k--)
        // {
        //     res[j][k] = max(res[j][k], res[j - cost1[i]][k - cost2[i]] + 1);
        // }
        cout << endl;
        return res[N - 1][V1][V2];
    }
};
int main()
{
    vector<string> myvec;
    string str;
    while (cin >> str)
    {
        myvec.push_back(str);
    }
    Solution sol;
    // int m, n;
    // cin >> m >> n;
    cout << sol.findMaxForm(myvec, 5, 3);
    return 0;
}