#include <iostream>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n, k;
    cin >> n >> k;
    int place[101][101];
    for (int i = 0; i < k; i++) {
        int x, y;
        string str;
        cin >> x >> y >> str;
        for (char ch : str) {
            if (ch == 'f' && y + 1 <= n)
                y += 1;
            else if (ch == 'b' && y - 1 > 0)
                y -= 1;
            else if (ch == 'l' && x - 1 > 0)
                x -= 1;
            else if (ch == 'r' && x + 1 <= n)
                x += 1;
        }
        cout << x << " " << y << "\n";
    }
    return 0;
}