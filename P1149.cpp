// # 抄的题解
#include <iostream>
using namespace std;
int a[3000]={6};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int ans = 0;
    int N;
    cin >> N;
    int c[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
    for (int i = 0; i <= 2000; i++)
    {
        int j = i;
        while (j)
        {
            a[i] = a[i] + c[j % 10];
            j /= 10;
        }
    }
    for (int i = 0; i <= 1000; i++)
    {
        for (int j = 0; j <= 1000; j++)
            if (a[i] + a[j] + a[i + j] + 4 == N)
                ans++;
    }
    cout << ans;
    return 0;
}