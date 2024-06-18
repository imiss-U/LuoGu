// # 抄的题解
#include <iostream>
using namespace std;
long long f[25][25];
bool visit[25][25];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n, m, hx, hy;
    cin >> n >> m >> hx >> hy;
    f[0][0] = 1;
    visit[hx][hy] = true;
    visit[hx - 2][hy - 1] = true;
    visit[hx - 2][hy + 1] = true;
    visit[hx + 2][hy - 1] = true;
    visit[hx + 2][hy + 1] = true;
    visit[hx - 1][hy + 2] = true;
    visit[hx - 1][hy - 2] = true;
    visit[hx + 1][hy + 2] = true;
    visit[hx + 1][hy - 2] = true;
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= m; j++) {
            if (!visit[i][j]) {
                if (i)
                    f[i][j] += f[i - 1][j];
                if (j)
                    f[i][j] += f[i][j - 1];
            }
        }
    cout << f[n][m];
    return 0;
}