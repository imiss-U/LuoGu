#include <iostream>
#include <cmath>
using namespace std;
int res[100009];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    for (int i = 1; i < 100009; i++)
        res[i] = 2000000000;
    int N;
    cin >> N;
    for (int i = 1; i <= pow(N, 0.25); i++) {
        for (int j = i * i * i * i; j <= N; j++) {
            if (j >= i * i * i * i)
                res[j] = min(res[j], res[j - i * i * i * i] + 1);
        }
    }
    cout << res[N];
    return 0;
}
