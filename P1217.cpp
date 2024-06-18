#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
bool IS_prim(int m)
{
    for (int i = 2; i <= sqrt(m); i++)
        if (m % i == 0)
            return false;
    return true;
}
bool f(int m)
{
    string str = to_string(m);
    string str2 = to_string(m);
    reverse(str2.begin(), str2.end());
    if (str == str2)
        return true;
    return false;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int a, b;
    bool flag = true;
    cin >> a >> b;
    if (a == 2)
        cout << 2 << "\n";
    if (b > 9999999)
        b = 9999999;
    if (a % 2 == 0)
        a++;
    for (int k = a; k <= b; k += 2)
    {
        if (f(k))
            if (IS_prim(k))
                cout << k << "\n";
            else
                continue;
    }
    return 0;
}