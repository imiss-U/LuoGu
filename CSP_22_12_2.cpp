#include <iostream>
#include <vector>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    bool flag = true;
    int n, m;
    cin >> m >> n;
    vector<int> time(n + 1), order(n + 1), early(n + 1), late(n + 1);
    early[1] = 1;
    for (int i = 1; i <= n; i++)
        cin >> order[i];
    for (int i = 1; i <= n; i++)
        cin >> time[i];


    for (int i = 2; i <= n; i++) {
        if (order[i] == 0)
            early[i] = 1;
        else
            early[i] = early[order[i]] + time[order[i]];

        if (early[i] + time[i] - 1 > m)
            flag = false;
    }

    for (int i = 1; i <= n; i++)
        cout << early[i] << " ";
    cout << "\n";
    if (!flag) {
        return 0;
    }

    for (int i = n; i >= 1; i--) {
        int tmp = 366;
        for (int j = i + 1; j <= n; j++) {
            if (order[j] == i)
                tmp = min(tmp, late[j]);
        }
        if (tmp == 366)
            late[i] = m + 1 - time[i];
        else
            late[i] = tmp - time[i];

    }
    for (int i = 1; i <= n; i++)
        cout << late[i] << " ";
    return 0;
}