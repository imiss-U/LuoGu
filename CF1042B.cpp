#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;
int convert(string& str) {
    int res = 0;
    for (auto i : str)
        if (i == 'A')
            res |= 1;
        else if (i == 'B')
            res |= 2;
        else if (i == 'C')
            res |= 4;
    return res;
}
int main() {
    int n;
    cin >> n;
    vector<int> c(n);
    vector<string> str(n);
    for (int i = 0; i < n;i++)
        cin >> c[i] >> str[i];
    vector<int> v(8, 0x3f3f3f3f);
    v[0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 7; j >= 0 ; j--) {
            v[j | convert(str[i])] = min(v[j | convert(str[i])], v[j] + c[i]);
        }
    }
    if (v[7] == 0x3f3f3f3f)
        cout << -1 << endl;
    else
        cout << v[7] << endl;
    return 0;
}