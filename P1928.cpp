// # 抄的题解
// # 原题解有个不足之处就是21行没写返回值 导致本地没有输出 加上就好了
#include <iostream>
using namespace std;
string diszip() {
    int k;
    string res = "", tmp = "";
    char ch;
    while (cin >> ch && ch) {
        if (ch == '[') {
            cin >> k;
            tmp = diszip();
            while (k--)
                res = res + tmp;
        }
        else if (ch == ']')
            return res;
        else
            res = res + ch;
    }
    return res;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << diszip();
    return 0;
}
