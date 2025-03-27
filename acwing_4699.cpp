#include <iostream>
#include <vector>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n, temp = 0;
    long long m;
    cin >> n >> m;
    vector<int> a(n + 1), c(n + 1), b(n + 1);
    c[0] = 1;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        c[i] = a[i] * c[i - 1];
        b[i] = (m % c[i] - temp) / c[i - 1];
        temp = m % c[i];
    }
    for (int i = 1; i <= n; i++)
        cout << b[i] << " ";
    return 0;
}