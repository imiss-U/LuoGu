#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(string s1, string s2)
{
    if (s1.size() < s2.size())
        return true;
    else if (s1.size() > s2.size())
        return false;
    else
    {
        if (s1[0] < s2[0])
            return true;
        else if (s1[0] > s2[0])
            return false;
        return cmp(s1.erase(0, 1), s2.erase(0, 1));
    }
}
int main()
{
    int n;
    cin >> n;
    vector<string> n1;
    for (int i = 0; i < n; i++)
    {
        string temp;
        cin >> temp;
        n1.emplace_back(temp);
    }
    auto max_ele = max_element(n1.begin(), n1.end(), cmp);
    cout << max_ele - n1.begin() + 1 << "\n"
         << *max_ele;
    return 0;
}