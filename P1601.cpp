#include <iostream>
#include <vector>
using namespace std;
string Add(string& a, string& b) {
    int lena = a.size(), lenb = b.size(), len = max(lena, lenb);
    vector<int> numa(len), numb(len);
    for (int i = 0; i < lena; i++)
        numa[i] = a[lena - 1 - i] - '0';
    for (int i = 0; i < lenb; i++)
        numb[i] = b[lenb - 1 - i] - '0';
    vector<int> res(max(lena, lenb) + 1);
    int loc = 0;
    for (int i = 0; i < max(lena, lenb); i++) {
        int temp = numa[i] + numb[i] + loc;
        res[i] = temp % 10;
        loc = temp / 10;
    }
    if (loc != 0) {
        res[max(lena, lenb)] = loc;
        len++;
    }
    string ans;
    for (int i = len - 1; i >= 0; i--)
        ans = ans + char(res[i] + 48);
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    string a, b;
    cin >> a >> b;
    cout << Add(a, b);
    return 0;
}