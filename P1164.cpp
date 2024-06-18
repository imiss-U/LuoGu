#include <iostream>
using namespace std;
int res[101];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int N, M;
    cin >> N >> M;
    int val[101];
    for (int i = 1; i <= N; i++)
        cin >> val[i];
    res[0] = 1;
    for (int i = 1; i <= N; i++)
        for (int j = M; j >= val[i]; j--) {
            res[j] += res[j - val[i]];
        }
    cout << res[M];
    return 0;
}
