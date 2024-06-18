#include <iostream>
#include <unordered_set>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    unordered_set<string> uset;
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        uset.insert(str);
    }
    cout << uset.size();
    return 0;
}