#include <iostream>
#include <vector>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<int> sum(n + 1);
    sum[0] = 0;
    sum[1] = -1;
    sum[2] = -1;
    sum[3] = 1;
    sum[4] = -1;
    sum[5] = 1;
    for (int i = 6; i <= n; i++) {
        if (sum[i - 3] == -1 && sum[i - 5] == -1)
            sum[i] = -1;
        else {
            if (sum[i - 3] == -1)
                sum[i] = sum[i - 5] + 1;
            else if (sum[i - 5] == -1)
                sum[i] = sum[i - 3] + 1;
            else
                sum[i] = min(sum[i - 3] + 1, sum[i - 5] + 1);
        }
    }
    cout << sum[n];
    return 0;
}