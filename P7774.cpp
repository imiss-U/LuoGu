// # 抄滴题解喵
#include <iostream>
#include <vector>

using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int N, M;
    cin >> N >> M;
    vector<int> a(N), b(M);
    vector<int> f(1010);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    f[0] = 1;
    for (int i = 0; i < N; i++) {
        for (int j = a[i]; j < 1010; j++) {                     // ! 警钟撅烂！！！从a[i]开始不是0
            f[j % 360] = max(f[j % 360], f[(j - a[i]) % 360]);
            f[j % 360] = max(f[j % 360], f[(j + a[i]) % 360]);
        }
    }
    for (int j = 0; j < M; j++) {
        cin >> b[j];
        if (f[b[j]] == 1)
            cout << "YES" << "\n";
        else
            cout << "NO" << "\n";
    }
    return 0;
}