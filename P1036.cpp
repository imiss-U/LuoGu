#include <iostream>
#include <vector>
using namespace std;
bool Is_prim(int num)
{
    if (num == 0 && num == 1)
        return false;
    if (num == 2)
        return true;
    for (int i = 2; i < num; i++)
        if (num % i == 0)
            return false;
    return true;
}
int main()
{
    int n, k, ans = 0;
    cin >> n >> k;
    vector<int> nums;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        nums.push_back(temp);
    }
    int len = nums.size(), limit = 1 << len;
    vector<vector<int>> res(limit);
    for (int i = 0; i < limit; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if ((i >> j) & 1)
                res[i].push_back(nums[j]);
        }
    }
    for (auto &x : res)
        if (x.size() == k)
        {
            int sum = 0;
            for (auto &y : x)
                sum += y;
            if (Is_prim(sum))
                ans++;
        }
    cout << ans;
    return 0;
}