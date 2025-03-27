// & 题解区偶遇优化大神，方法复杂多变种类繁多，拼尽全力无法战胜。该代码task1能过，task2过不去

#include <iostream>
#include <vector>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<int> f(n + 1), Sum(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> f[i];
        Sum[i] = Sum[i - 1] + f[i];
    }
    int len = 0;
    for (int i = 1; i <= n - len; i++) {
        for (int j = i + 1; j <= n; j += 2) {
            if (j - i + 1 < len)
                continue;
            if (Sum[j] == Sum[j - 1])
                continue;
            if (2 * (Sum[j] - Sum[i - 1]) == (j - i + 1))
                len = j - i + 1;
        }
    }
    cout << len;
    return 0;
}