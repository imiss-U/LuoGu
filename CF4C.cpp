#include <iostream>
#include <unordered_map>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    unordered_map<string, int> umap;
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        if (umap.contains(str)) {
            cout << str << umap[str] << "\n";
            umap[str]++;
        }
        else {
            cout << "OK" << "\n";
            umap.insert({str, 1});
        }
    }
    return 0;
}