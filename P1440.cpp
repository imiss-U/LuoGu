#include <iostream>
#include <deque>
using namespace std;
int a[2000001];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    cout << "0" << "\n";
    deque<int> q;
    q.push_back(1);
    for (int j = 2; j <= n; j++) {
        while (!q.empty() && j - q.front() > m)
            q.pop_front();
        cout << a[q.front()] << "\n";
        while (!q.empty() && a[q.back()] >= a[j])
            q.pop_back();
        q.push_back(j);
    }
    return 0;
}