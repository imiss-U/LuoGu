#include <iostream>
#include <vector>

using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<int> uves(n + 1);
    int i , k;
    for (i = 1; i <= n; i += 2)
        uves[i] = (i + 1) / 2;
    k = i;
}