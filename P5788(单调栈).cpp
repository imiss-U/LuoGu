#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    stack<int> s;
    vector<int> ves(n), res(n);
    for (int i = 0; i < n; i++)
        cin >> ves[i];
    for (int i = 0; i < n; i++) {
        while (!s.empty() && ves[s.top()] < ves[i]) {
            res[s.top()] = i + 1;
            s.pop();
        }
        s.push(i);
    }
    for (int i = 0; i < n; i++)
        cout << res[i] << " ";
    return 0;
}