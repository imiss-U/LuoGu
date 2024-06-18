#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(string s1, string s2)
{
    return (s1 + s2) > (s2 + s1);
}
int main()
{
    int n;
    vector<string> v;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        v.push_back(str);
    }
    sort(v.begin(), v.end(), cmp);
    for (auto &x : v)
        cout << x;
    return 0;
}