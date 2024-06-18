#include <iostream>
using namespace std;
long long res[50100];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    long long C, H;
    cin >> C >> H;
    long long volum[50100];
    for (long long i = 1; i <= H; i++)
    {
        cin >> volum[i];
    }
    for (long long i = 1; i <= H; i++)
    {
        for (long long j = C; j >= volum[i]; j--)
        {
            res[j] = max(res[j], res[j - volum[i]] + volum[i]);
        }
    }
    cout << res[C];
    return 0;
}