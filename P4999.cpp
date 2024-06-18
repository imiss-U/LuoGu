// * 俺的第一道数位dp题！
// * 虽然也是抄的题解
// * 有关数位dp的东西看markdown去 这里只说明一点：遇到求余的问题39行那里不要忘记在求余之前加个mod 容易出现负数
#include <iostream>
#include <vector>
using namespace std;
int num[19];
const int mod = 1e9 + 7;
vector<vector<long long>> dp(200, vector<long long>(200, -1));
long long dfs(int pos, bool limit, int sum){
    if (pos == 0)
        return sum;
    if (!limit && dp[pos][sum] >= 0)
        return dp[pos][sum];
    int up = limit ? num[pos] : 9;
    long long res = 0;
    for (int i = 0; i <= up; i++)
        res = (res + dfs(pos - 1, limit && (i == up), sum + i)) % mod;
    if (!limit)
        dp[pos][sum] = res;
    return res;
}
long long solve(long long x) {
    int len = 0;
    while(x) {
        num[++len] = x % 10;
        x /= 10;
    }
    return dfs(len, true, 0);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        long long Left, Right;
        cin >> Left >> Right;
        cout << (solve(Right) - solve(Left - 1) + mod) % mod << "\n";
    }
    return 0;
}