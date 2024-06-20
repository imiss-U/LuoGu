// * 1.不开long long _ _ _
// * 2.有点写着急了嗷……思路不难就是情况有点多 没一遍AC
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    long long n, x;
    cin >> n >> x;
    vector<long long> c(n);
    for (long long i = 0; i < n; i++)
        cin >> c[i];
    sort(c.begin(), c.end());
    if (c[0] < x) {
        cout << -1;
        return 0;
    }
    for (long long i = 1; i < n; i++) {
        if ((c[i] - c[i - 1]) % x != 0) {
            cout << -1;
            return 0;
        }
    }
    cout << c[0] - x;
    return 0;
}