#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1), Sum(n + 1), Max(n + 1), index(n + 1);
    for (int i = 0; i < n + 1; i++)
        cin >> a[i];
    Max[0] = a[0], index[0] = 0;
    for (int i = 1; i < n + 1; i++) {
        cin >> b[i];
        Sum[i] = Sum[i - 1] + a[i] - b[i];
        if (Max[i - 1] >= Sum[i] + a[0]) {
            Max[i] = Max[i - 1];
            index[i] = index[i - 1];
        }
        else {
            Max[i] = Sum[i] + a[0];
            index[i] = i;
        }
    }
    int inplace = max_element(Sum.begin() + 1, Sum.end()) - Sum.begin() - 1;
    for (int i = 1; i <= n; i++) {
        if (index[i] < index[n])
            cout << Max[n] + b[i] << " ";
        else {
            if (i >= inplace)
                inplace = max_element(Sum.begin() + i, Sum.end()) - Sum.begin() - i;
            if (Sum[inplace] + a[0] + b[i] > Max[n])
                cout << Sum[inplace] + a[0] + b[i] << " ";
            else
                cout << Max[n] << " ";
        }
    }
    return 0;
}