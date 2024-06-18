#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int n, r;
    cin >> n >> r;
    vector<int> nums;
    for (int i = 1; i <= n; i++)
    {
        nums.push_back(i);
    }
    int count = 1 << n;
    vector<vector<int>> res(count);
    for (int i = 0; i < count; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if ((i >> j) & 1)
                res[i].push_back(nums[j]);
        }
    }
    sort(res.begin(), res.end());
    for (auto &x : res)
    {
        if (x.size() == r)
        {
            for (auto y : x)
            {
                cout.width(3);
                cout << y;
            }
            cout << "\n";
        }
    }
    return 0;
}