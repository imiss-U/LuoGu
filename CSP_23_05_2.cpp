#include <iostream>
#include <vector>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, d;
    cin >> n >> d;
    vector<vector<int>> Q(n, vector<int>(d)), K(n, vector<int>(d)), V(n, vector<int>(d));
    vector<int> W(n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < d; j++)
            cin >> Q[i][j];
    for (int j = 0; j < n; j++)
        for (int i = 0; i < d; i++)
            cin >> K[j][i];
    for (int j = 0; j < n; j++)
        for (int i = 0; i < d; i++)
            cin >> V[j][i];
    for (int i = 0; i < n; i++)
        cin >> W[i];
    vector<vector<long long>> res(d, vector<long long>(d));
    for (int i = 0; i < d; i++) {
        for (int j = 0; j < d; j++) {
            for (int k = 0; k < n; k++) {
                res[i][j] += K[k][i] * V[k][j];
            }
        }
    }
    vector<long long> ans(d);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < d; j++) {
            for (int k = 0; k < d; k++) {
                ans[j] += Q[i][k] * res[k][j];
            }
            cout << ans[j] * W[i] << ' ';
        }
        cout << '\n';
        ans.assign(d, 0);
    }
    return 0;
}