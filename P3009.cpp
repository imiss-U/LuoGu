// # 注释掉的部分是原来自己写的  用二维数组会MLE，用两层循环就会TLE。。。。
// # 于是又看了题解，用dp做的 最后过了
// # 没用前缀和试过 估计也会超时（毕竟也得用两层循环）
#include <iostream>
#include <vector>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int N;
    cin >> N;
    vector<int> profile(N + 1);
    for (int i = 1; i <= N; i++)
        cin >> profile[i];
    // int maxProfile = profile[1];
    // vector<int> total(N + 1);
    // for (int i = 1; i <= N; i++) {
    //     total[i - 1] = 0;
    //     for (int j = i; j <= N; j++) {
    //         total[j] = total[j - 1] + profile[j];
    //         maxProfile = total[j] > maxProfile ? total[j] : maxProfile;
    //     }
    // }
    // cout << maxProfile;
    int maxProfile = -100000;
    vector<int> total(N + 1);
    for (int i = 1; i <= N; i++) {
        total[i] = max(total[i - 1] + profile[i], profile[i]);
        maxProfile = total[i] > maxProfile ? total[i] : maxProfile;
    }
    cout << maxProfile;
    return 0;
}