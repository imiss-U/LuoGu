#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
void update(int i, int val, vector<int>& ves) {
    for (; i <= n; i += i & -i)
        ves[i] += val;
}
long long query(int i, vector<int>& ves) {
    long long sum = 0;
    for (; i > 0; i -= i & -i)
        sum += ves[i];
    return sum;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n;
    vector<int> BIT1(n + 1), BIT2(n + 1);
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        update(i + 1, a[i], BIT1);
    vector<long long> res(n + 1);
    long long ans = 0;
    for (int i = 1; i <= n; i++)
        res[i] = query(i, BIT1);
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++)
        update(i + 1, a[i], BIT2);
    for (int i = 1; i <= n; i++) {
        long long tmp = query(i, BIT2);
        if (tmp != res[i])
            ans++;
    }
    cout << ans;
    return 0;
}