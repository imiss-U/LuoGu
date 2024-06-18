#include <iostream>
#include <vector>
using namespace std;
int res[10010]; // ! 这种写法在本地可以通过，但是在力扣上过不去（因为力扣上不提供主函数，因此个人猜测系统并没有将res当作全局变量全部初始化为0，因此造成错误）
class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {
        int sum = 0;
        for (auto x : nums)
        {
            sum += x;
        }
        if (sum % 2 != 0)
            return false;
        else
        {
            int V = sum / 2;
            int N = nums.size();
            for (int i = 0; i < N; i++)
            {
                for (int j = V; j >= nums[i]; j--)
                {
                    res[j] = max(res[j], res[j - nums[i]] + nums[i]);
                }
            }
            for (int i = N - 1, j = V; res[j] && i >=0; i--)
            {
                if (res[j] == res[j - nums[i]] + nums[i])
                {
                    cout << i << " ";
                    j -= nums[i];
                }
            }
            if (res[V] == V)
                return true;
            return false;
        }
    }
};
int main()
{
    vector<int> myvec;
    int tmp;
    while (cin >> tmp)
    {
        myvec.push_back(tmp);
    }
    Solution sol;
    sol.canPartition(myvec);
    return 0;
}