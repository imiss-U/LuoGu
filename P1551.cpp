#include <iostream>
#include <vector>
using namespace std;
struct dsu {
    vector<int> fa;
    dsu(int n) : fa(n + 1) {
        for (int i = 1; i <= n; i++)
            fa[i] = i;
    }

    int find(int i) {
        return (fa[i] == i) ? i : find(fa[i]);
    }

    void merge(int x, int y) {
        fa[find(x)] = find(y);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n, m, p;
    cin >> n >> m >> p;
    dsu Dsu(n);
    for (int i = 0; i < m; i++) {
        int M1, M2;
        cin >> M1 >> M2;
        Dsu.merge(M1, M2);
    }
    for (int i = 0; i < p; i++) {
        int p1, p2;
        cin >> p1 >> p2;
        cout << ((Dsu.find(p1) == Dsu.find(p2)) ? "Yes" : "No") << "\n";
    }
    return 0;
}