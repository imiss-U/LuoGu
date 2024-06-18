#include <iostream>
#include <vector>
using namespace std;
string Add(string& a, string& b) {
    vector<int> res(max(a.size(), b.size()) + 1), numa(res.size()), numb(res.size());
    for (int i = 0; i < a.size(); i++)
        numa[i] = a[a.size() - 1 - i] - '0';
    for (int j = 0; j < b.size(); j++)
        numb[j] = b[b.size() - 1 - j] - '0';
    int loc = 0;
    for (int k = 0; k < res.size(); k++) {
        int temp = numa[k] + numb[k] + loc; // ! 警钟撅烂！先加loc再求余，否则还会超过10（第四个测试点）
        res[k] = temp % 10;
        loc = temp / 10;
    }
    int tmp = res.size();
    while (res[tmp - 1] == 0)
        tmp--;
    string ans;
    while (tmp--)
        ans = ans + char(res[tmp] + 48);
    return ans;
}
string Mul(string& a, string& b) {
    vector<int> res(a.size() + b.size()), numa(a.size()), numb(b.size());
    for (int i = 0; i < a.size(); i++)
        numa[i] = a[a.size() - 1 - i] - '0';
    for (int j = 0; j < b.size(); j++)
        numb[j] = b[b.size() - 1 - j] - '0';
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < b.size(); j++) {
            res[i + j] += numa[i] * numb[j];
            res[i + j + 1] += res[i + j] / 10;
            res[i + j] %= 10;
        }
    }
    int tmp = res.size();
    while (res[tmp - 1] == 0)
        tmp--;
    string ans;
    while (tmp--)
        ans = ans + char(res[tmp] + 48);
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    string ans = "1", res = "0";
    for (int i = 1; i <= n; i++) {
        string tmp = to_string(i);
        ans.assign(Mul(ans, tmp));
        res.assign(Add(res, ans));
    }
    cout << res;
    return 0;
}