#include <iostream>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    int sum = 0, w, score;
    for (int i = 0; i < n; i++) {
        cin >> w >> score;
        sum += w * score;
    }
    cout << max(0, sum);
    return 0;
}