#include <iostream>
using namespace std;
string f[1010];
string Sum(string &a, string &b)
{
    if (a.size() > b.size())
    {
        int tmp = a.size() - b.size();
        while (tmp--)
        {
            b = '0' + b;
        }
    }
    if (a.size() < b.size())
    {
        int tmp = b.size() - a.size();
        while (tmp--)
        {
            a = '0' + a;
        }
    }
    int pos = a.size() - 1;
    int loc = 0;
    string res = "";
    for (; pos >= 0; pos--)
    {
        int data = a[pos] - '0' + b[pos] - '0' + loc;
        char ch = char(data % 10 + 48);
        loc = data / 10;
        res = ch + res;
    }
    if (loc)
        return '1' + res;
    return res;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int M, N;
    cin >> M >> N;
    f[M + 1] = "1";
    f[M + 2] = "1";
    for (int i = M + 3; i <= N + 1; i++)
    {
        f[i] = Sum(f[i - 1], f[i - 2]);
    }
    cout << f[N + 1];
    return 0;
}