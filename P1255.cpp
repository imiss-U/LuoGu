#include <iostream>
using namespace std;
string Sum(string &a, string &b)
{
    if (a.size() > b.size())
    {
        int zero = a.size() - b.size();
        while (zero--)
            b = '0' + b;
    }
    if (a.size() < b.size())
    {
        int zero = b.size() - a.size();
        while (zero--)
            a = '0' + a;
    }
    int pos = a.size() - 1;
    int loc = 0;
    string ans = "";
    for (int i = pos; i >= 0; i--)
    {
        int num = a[i] - '0' + b[i] - '0' + loc;
        ans = char(num % 10 + 48) + ans;
        loc = num / 10;
    }
    if (loc)
        return char(loc + 48) + ans;
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int N;
    cin >> N;
    string f[5010];
    f[1] = '1';
    f[2] = '2';
    for (int i = 3; i <= N; i++)
        f[i] = Sum(f[i - 1], f[i - 2]);
    cout << f[N];
    return 0;
}