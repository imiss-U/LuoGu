#include <iostream>
#include <unordered_set>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        unordered_set<int> myset;
        int temp;
        for (int i = 0; i < N; i++) {
            cin >> temp;
            if (!myset.contains(temp))
                cout << temp << " ";
            myset.insert(temp);
        }
        cout << "\n";
    }
    return 0;
}