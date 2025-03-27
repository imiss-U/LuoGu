#include <iostream>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(), cout.tie(0);
    int n, a, b;
    cin >> n >> a >> b;
    long long S = 0;
    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if (x2 < 0 || y2 < 0 || x1 > a || y1 > b) continue;
        if (x1 < 0) x1 = 0;
        if (y1 < 0) y1 = 0;
        if (x2 > a) x2 = a;
        if (y2 > b) y2 = b;
        S += (x2 - x1) * (y2 - y1);
    }
    cout << S;
    return 0;
}