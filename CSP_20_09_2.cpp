#include <iostream>
#include <vector>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, k, t, xl, yd, xr, yu;
    int num1 = 0, num2 = 0;
    cin >> n >> k >> t >> xl >> yd >> xr >> yu;
    for (int i = 0; i < n; i++) {
        int x1, yi;
        bool flag1 = false, flag2 = false;          // flag1:是否曾经在区域内，flag2:是否满足条件，只要为true就不再判断
        int stay = 0;                               // stay:在区域内的连续时间
        for (int i = 0; i < t; i++) {
            cin >> x1 >> yi;
            if (flag2)
                continue;
            if (x1 >= xl && x1 <= xr && yi >= yd && yi <= yu) {
                if (flag1 == false) {
                    num1++;
                    flag1 = true;
                }
                stay++;
                if (stay >= k) {
                    num2++;
                    flag2 = true;
                }
            }
            else
                stay = 0;
        }
    }
    cout << num1 << '\n' << num2;
    return 0;
}