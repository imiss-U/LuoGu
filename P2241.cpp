// # 看的题解
#include <iostream>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    long long sum1 = 0, sum2 = 0;// 首次用int超范围了
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            sum1 += min(i, j);
            sum2 += i * j;
        }
    }
    cout << sum1 << " " << sum2 - sum1;
    return 0;
}