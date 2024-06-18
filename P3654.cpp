// # 不用all_of 嗷 用了反而麻烦  因为没法竖着遍历  不如直接用数组下标挨个判断
#include <iostream>
#include <algorithm>
using namespace std;
bool Empty(char ch)
{
    if (ch == '.')
        return true;
    return false;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    char map1[110][110], map2[110][110];
    int R, C, K;
    cin >> R >> C >> K;
    for (int i = 0; i <= R + 1; i++)
    {
        map1[i][0] = '#';
        map1[i][C + 1] = '#';
    }
    for (int j = 0; j <= C + 1; j++)
    {
        map1[0][j] = '#';
        map1[C + 1][j] = '#';
    }
    for (int i = 0; i < C + 1; i++)
    {
        map2[i][0] = '#';
        map2[i][R + 1] = '#';
    }
    for (int j = 0; j <= R + 1; j++)
    {
        map2[0][j] = '#';
        map2[R + 1][j] = '#';
    }
    for (int i = 1; i <= R; i++)
        for (int j = 1; j <= C; j++)
        {
            cin >> map1[i][j];
            map2[j][i] = map1[i][j];
        }
    int ans = 0;
    for (int index = 1; index <= R; index++)
    {
        for (int rol = 1; rol <= C - K + 1; rol++)
            if (all_of(map1[index] + rol, map1[index] + rol + K, Empty))
                ans++;
    }
    for (int index = 1; index <= C; index++)
    {
        for (int rol = 1; rol <= R - K + 1; rol++)
            if (all_of(map2[index] + rol, map2[index] + rol + K, Empty))
                ans++;
    }
    if (K == 1)
        ans /= 2;
    cout << ans;
    return 0;
}