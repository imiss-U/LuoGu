#include <iostream>
#include <vector>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    vector<vector<char>> a(n * 8, vector<char>(8));
    for (int i = 0; i < n * 8; i++) {
        for (int j = 0; j < 8; j++) {
            cin >> a[i][j];
        }
    }
    bool flag = true;
    cout << 1 << '\n';
    for (int i = 1; i < n; i++) {                                   // 第i个矩阵
        int cnt = 1;
        for (int s = 0; s < i; s++) {                               // 前s个矩阵
            for (int j = 0; j < 8; j++) {                           // 第j行       
                for (int k = 0; k < 8; k++) {                       // 第k列
                    if (a[i * 8 + j][k] != a[s * 8 + j][k]) {
                        flag = false;
                        break;
                    }
                    if (!flag)
                        break;
                }
                if (!flag)
                    break;
            }
            if (flag)
                cnt++;
            else {
                flag = true;
                continue;
            }
        }
        cout << cnt << "\n";
    }
    return 0;
}