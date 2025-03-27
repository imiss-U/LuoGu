#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    string str;
    set<string> N, M;
    for (int i = 0; i < n; i++) {
        cin >> str;
        transform(str.begin(), str.end(), str.begin(), ::tolower);
        N.insert(str);
    }
    for (int i = 0; i < m; i++) {
        cin >> str;
        transform(str.begin(), str.end(), str.begin(), ::tolower);
        M.insert(str);
    }
    vector<string> res1, res2;

    set_intersection(N.begin(), N.end(), M.begin(), M.end(), inserter(res1, res1.begin()));
    res1.erase(unique(res1.begin(), res1.end()), res1.end());

    set_union(N.begin(), N.end(), M.begin(), M.end(), inserter(res2, res2.begin()));// 并集
    res2.erase(unique(res2.begin(), res2.end()), res2.end());

    cout << res1.size() << "\n" << res2.size();
    return 0;
}