#include <iostream>
using namespace std;
int f[3], c[3];
char map[12][12];
bool flag[200000];
void move(int t[])
{
    if (t[0] == 0)
    {
        if (map[t[1] - 1][t[2]] == '*')
        {
            t[0] = (t[0] + 1) % 4;
        }
        else
        {
            t[1] = t[1] - 1;
        }
    }
    else if (t[0] == 1)
    {
        if (map[t[1]][t[2] + 1] == '*')
        {
            t[0] = (t[0] + 1) % 4;
        }
        else
        {
            t[2] = t[2] + 1;
        }
    }
    else if (t[0] == 2)
    {
        if (map[t[1] + 1][t[2]] == '*')
        {
            t[0] = (t[0] + 1) % 4;
        }
        else
        {
            t[1] = t[1] + 1;
        }
    }
    else
    {
        if (map[t[1]][t[2] - 1] == '*')
        {
            t[0] = (t[0] + 1) % 4;
        }
        else
        {
            t[2] = t[2] - 1;
        }
    }
}
bool meet(int f[], int c[])
{
    return f[1] == c[1] && f[2] == c[2];
}
int main()
{
    int ans = 0;
    f[0] = 0, c[0] = 0;
    for (int i = 1; i < 11; i++)
    {
        for (int j = 1; j < 11; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == 'F')
            {
                f[1] = i;
                f[2] = j;
            }
            if (map[i][j] == 'C')
            {
                c[1] = i;
                c[2] = j;
            }
        }
    }
    for (int i = 0; i < 12; i++)
    {
        map[0][i] = '*';
        map[11][i] = '*';
    }
    for (int j = 0; j < 12; j++)
    {
        map[j][0] = '*';
        map[j][11] = '*';
    }
    while (!meet(f, c))
    {
        int p = f[1] + f[2] * 10 + c[1] * 100 + c[2] * 1000 + f[0] * 10000 + c[0] * 40000;
        if (flag[p])
        {
            cout << 0;
            return 0;
        }
        flag[p] = true;
        move(f);
        move(c);
        ans++;
    }
    cout << ans;
    return 0;
}