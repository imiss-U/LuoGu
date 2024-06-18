#include <iostream>
#include <vector>
using namespace std;
string mul(string& a, string& b) {
    if (a == "0" || b == "0")   //! 警钟撅烂！ 别忘！
        return "0";
    int lena = a.size(), lenb = b.size(), len = lena + lenb;
    vector<int> numa(lena), numb(lenb), res(len);
    for (int i = 0; i < lena; i++)
        numa[i] = a[lena - 1 - i] - '0';// ! 撅烂！是lena lenb 不是len
    for (int i = 0; i < lenb; i++)
        numb[i] = b[lenb - 1 - i] - '0';
    int i, j;
    for (i = 0; i < lena; i++) {
        for (j = 0; j < lenb; j++) {
            res[i + j] += numa[i] * numb[j];//! 撅烂！ +=不是=
            res[i + j + 1] += res[i + j] / 10;
            res[i + j] %= 10;
        }
    }
    string ans;
    len = i + j;
    while (res[len - 1] == 0 && len > 0)//!撅烂撅烂！别忘
        len--;
    for (int i = len - 1; i >= 0; i--)
        ans = ans + char(res[i] + 48);
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    string a, b;
    cin >> a >> b;
    cout << mul(a, b);
    return 0;
}