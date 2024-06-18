#include <iostream>
#include <vector>
using namespace std;
int num[20];
vector<vector<long long>> dp(200, vector<long long>(200, -1));
vector<long long> left(10);
vector<long long> Right(10);
long long dfs(int pos, bool limit, int sum) {
    if (pos == 0)
        return sum;
    if (!limit && dp[pos][sum])
        return dp[pos][sum];
    int up = limit ? num[pos] : 9;
    for (int i = 0; i <= up; i++)
        Right[i] += dfs(pos - 1, limit && (i == up), sum + i);
    // if (!limit)
    //     dp[pos][sum] = 
}
void solve(long long b){
    int len = 0;
    while(b) {
        num[++len] = b % 10;
        b /= 10;
    }

}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    long long a, b;
    cin >> a >> b;
    solve(a - 1);
    solve(b);
    // for (int i = 0; i < 10; i++)
        // cout << right[i] - left[i] << " ";
    return 0;
}