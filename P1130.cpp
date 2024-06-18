// # 抄的题解 19 20行的顺序不可调换 另外别忘记开long long
#include <iostream>
#include <vector>
using namespace std;
int maxTime = 1000000000;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int N, M;
    cin >> N >> M;
    vector<vector<int>> num(M + 1, vector<int>(N + 1));
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++)
            cin >> num[i][j];
    }
    vector<vector<long long>> dp(M + 1, vector<long long>(N + 1));
    for (int i = 0; i < M; i++)
        dp[i][0] = num[i][0];
    for (int j = 1; j < N; j++) {
        for (int i = 0; i < M; i++) {
            dp[i][j] = min(dp[i][j - 1], dp[(i - 1 + M) % M][j - 1]) + num[i][j];
            if (j == N - 1)
                maxTime = (dp[i][j] > maxTime) ? maxTime : dp[i][j];
        }
    }
    cout << maxTime;
    return 0;
}
