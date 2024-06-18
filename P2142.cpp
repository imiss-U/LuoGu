#include <iostream>
#include <vector>
using namespace std;
string Sub(string& a, string& b) {
    if (a == b)   return "0";           // ! 警钟撅烂！！！！！用了递归但是忘了一种情况导致第六个测试点卡了半天
    if (a.size() > b.size() || (a.size() == b.size() && a > b)) {
        int lena = a.size(), lenb = b.size(), len = max(a.size(), b.size());
        vector<int> numa(len), numb(len), res(len);
        for (int i = 0; i < lena; i++)
            numa[i] = a[lena - 1 - i] - '0';
        for (int i = 0; i < lenb; i++)
            numb[i] = b[lenb - 1 - i] - '0';
        int loc = 0;
        for (int i = 0; i < len; i++) {
            int temp = numa[i] - numb[i] - loc;
            if (temp < 0) {
                temp += 10;
                loc = 1;
            }
            else
                loc = 0;        // ! 同样警钟撅烂！！！ loc不能一直是1  别忘了改回来
            res[i] = temp;
        }
        while (res[len - 1] == 0 && len > 0) {
            len--;
        }
        string ans;
        for (int i = len - 1; i >= 0; i--)
            ans = ans + char(res[i] + 48);
        return ans;
    }
    else
        return "-" + Sub(b, a);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    string a, b;
    cin >> a >> b;
    cout << Sub(a, b);
    return 0;
}