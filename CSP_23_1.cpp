#include <iostream>
#include <vector>
#include <set>
using namespace std;
int m;
struct WareHouse {
    int id;
    int x[11];
    int parent;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n;
    cin >> n >> m;

    vector<WareHouse> wh(n);
    for (int i = 0; i < n; i++) {
        wh[i].id = i + 1;
        for (int j = 0; j < m; j++)
            cin >> wh[i].x[j];
    }
    for (int i = 0; i < n; i++) {
        set<int> s;
        for (int j = 0; j < n; j++)
            s.insert(wh[j].id);
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < n; k++) {
                if (wh[i].x[j] >= wh[k].x[j] && s.find(wh[k].id) != s.end())
                    s.erase(wh[k].id);
            }
        }
        if (s.empty())
            wh[i].parent = 0;
        else
            wh[i].parent = *s.begin();
        cout << wh[i].parent << "\n";
    }
    return 0;
}