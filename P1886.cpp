#include <iostream>
#include <deque>
#include <vector>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> num(n), pos(n);
    for (int i = 0; i < n; i++) cin >> num[i];
    deque<int> q;
    for (int i = 0; i < n; i++) {
        while (!q.empty() && q.front() < i - k + 1) q.pop_front();  // 这里的while不能改成if，因为可能会有多个元素被pop掉
        while (!q.empty() && num[q.back()] >= num[i]) q.pop_back();
        q.push_back(i);
        if (i >= k - 1) pos[i] = num[q.front()];
    }
    for (int i = k - 1; i < n; i++) cout << pos[i] << ' ';
    cout << endl;
    q.clear();
    for (int i = 0; i < n; i++) {
        while (!q.empty() && q.front() < i - k + 1) q.pop_front();
        while (!q.empty() && num[q.back()] <= num[i]) q.pop_back();
        q.push_back(i);
        if (i >= k - 1) pos[i] = num[q.front()];
    }
    for (int i = k - 1; i < n; i++) cout << pos[i] << ' ';
    cout << endl;
    return 0;
}