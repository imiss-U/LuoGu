#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;
using mytuple = tuple<int, string, int, int, int>;
bool cmp(mytuple m1, mytuple m2)
{
    if (get<2>(m1) < get<2>(m2))
        return true;
    else if (get<2>(m1) > get<2>(m2))
        return false;
    else
    {
        if (get<3>(m1) < get<3>(m2))
            return true;
        else if (get<3>(m1) > get<3>(m2))
            return false;
        else
        {
            if (get<4>(m1) < get<4>(m2))
                return true;
            else if (get<4>(m1) > get<4>(m2))
                return false;
            else
                return get<0>(m1) < get<2>(m2);
        }
    }
}
int main()
{
    int n;
    cin >> n;
    vector<mytuple> v;
    for (int i = 0; i < n; i++)
    {
        string str;
        int year, month, day;
        cin >> str >> year >> month >> day;
        mytuple mp = make_tuple(i + 1, str, year, month, day);
        v.push_back(mp);
    }
    stable_sort(v.begin(), v.end(), cmp);//! 这里用稳定排序才能过（stable_sort），常规排序过不了，看评论区可能是不稳定交换了两个元素顺序
    for (auto &x : v)
        cout << get<1>(x) << "\n";
    return 0;
}