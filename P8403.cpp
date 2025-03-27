#include <iostream>
#include <vector>
using namespace std;
struct DSU {
    vector<int> v;
    DSU(int n) : v(n) {
        for (int i = 0; i < n; i++) v[i] = i;
    }
    int find(int x) {
        return v[x] == x ? x : v[x] = find(v[x]);
    }
    void merge(int x, int y) {
        v[find(x)] = find(y);
    }
};
int Hash(string& str) {
    unsigned int res = 0;                   // ! int is not enough
    for (char c : str) res = (res * 63 + c);// ! 要加完再取模，不要每次都取模
    return res % (int)1e7;                   // ! 1e5 is not enough
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int x, y, g;
    cin >> x;
    vector<vector<string>> s(x, vector<string>(2));
    for (int i = 0; i < x; i++) cin >> s[i][0] >> s[i][1];
    cin >> y;
    vector<vector<string>> t(y, vector<string>(2));
    for (int i = 0; i < y; i++) cin >> t[i][0] >> t[i][1];
    cin >> g;
    DSU dsu(1e7);                // ! 1e5 is not enough
    for (int i = 0; i < g; i++) {
        string str1, str2, str3;
        cin >> str1 >> str2 >> str3;
        int a = Hash(str1), b = Hash(str3), c = Hash(str2);
        dsu.merge(a, c);
        dsu.merge(b, c);
    }
    long long res = 0;
    for (int i = 0; i < x; i++) {
        if (dsu.find(Hash(s[i][0])) != dsu.find(Hash(s[i][1]))) {
            res++;
        }
    }
    for (int j = 0; j < y; j++) {
        if (dsu.find(Hash(t[j][0])) == dsu.find(Hash(t[j][1]))) {
            res++;
        }
    }
    cout << res << endl;
    return 0;
}