// * 这题太水了啊  没开long long就过了
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> matrix(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> matrix[i][j];
    vector<vector<int>> res(n, vector<int>(m));
    vector<int> sum1(n), sum2(m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            sum1[i] += matrix[i][j];
    for (int j = 0; j < m; j++)
        for (int i = 0; i < n; i++)
            sum2[j] += matrix[i][j];
    vector<int> ans(n * m);
    int h = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            res[i][j] = sum1[i] + sum2[j] - matrix[i][j];
            ans[h++] = res[i][j];
        }
    sort(ans.begin(), ans.end());
    int count = 0;
    do {
        ans[k - 1] -= (n + m - 1);
        count++;
    }
    while (ans[k - 1] > 0);
    cout << count;
    return 0;
}