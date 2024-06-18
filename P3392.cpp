#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, M;
vector<vector<char>> mymap(51, vector<char>(51));
int ans = 2e9;
void f(int n, int m)
{
    int tmp = 0;
    for (int i = 1; i <= n; i++)
        tmp = tmp + M - count(mymap[i].begin(), mymap[i].end(), 'W');
    for (int j = N; j >= N - m + 1; j--)
        tmp = tmp + M - count(mymap[j].begin(), mymap[j].end(), 'R');
    for (int k = n + 1; k <= N - m; k++)
        tmp = tmp + M - count(mymap[k].begin(), mymap[k].end(), 'B');
    ans = min(ans, tmp);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            cin >> mymap[i][j];
    for (int i = 1; i <= N - 1; i++)
    {
        for (int j = 1; j <= N - 1; j++)
        {
            if (i + j + 1 > N)
                continue;
            f(i, j);
        }
    }
    cout << ans;
    return 0;
}