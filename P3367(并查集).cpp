#include <iostream>
#include <vector>
using namespace std;
struct dsu {
    vector<int> fa;
    dsu(int n) : fa(n + 1) {
        for (int i = 1; i <= n; i++) {
            fa[i] = i;
        }
    }
    int find(int x) {
        return fa[x] == x ? x : fa[x] = find(fa[x]);
    }
    void merge(int x, int y) {
        fa[find(x)] = find(y);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    dsu Dsu(n);
    for (int i = 0; i < m; i++) {
        int z, x, y;
        cin >> z >> x >> y;
        if (z == 1)
            Dsu.merge(x, y);
        else
            cout << (Dsu.find(x) == Dsu.find(y) ? "Y" : "N") << "\n";
    }
    return 0;
}