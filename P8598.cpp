#include <iostream>
using namespace std;
int flag[10010];
int minValue = 1000000, maxValue = 0;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int N;
    cin >> N;
    int tmp;
    while (cin >> tmp)
    {
        if (tmp < minValue)
            minValue = tmp;
        if (tmp > maxValue)
            maxValue = tmp;
        flag[tmp]++;
    }
    for (int i = minValue; i <= maxValue; i++)
    {
        if (flag[i] == 0)
        {
            cout << i << " ";
            break;
        }
    }
    for (int i = minValue; i <= maxValue; i++)
    {
        if (flag[i] == 2)
        {
            cout << i;
            break;
        }
    }
    return 0;
}