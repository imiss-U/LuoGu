#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <tuple>
#include <cstdio>
using namespace std;
using mytuple = tuple<int, int, int>;
bool cmp(mytuple m1, mytuple m2)
{
    return get<2>(m1) > get<2>(m2);
}
int main()
{
    int N;
    cin >> N;
    vector<mytuple> v;
    for (int i = 0; i < N; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        mytuple mt = make_tuple(x, y, z);
        v.push_back(mt);
    }
    sort(v.begin(), v.end(), cmp);
    double dis = 0;
    vector<mytuple>::iterator it1 = v.begin(), it = it1;
    it++;
    for (; it != v.end(); it++, it1++)
    {
        dis += hypot(get<0>(*it) - get<0>(*it1), get<1>(*it) - get<1>(*it1), get<2>(*it) - get<2>(*it1));
    }
    printf("%.3f", dis);
    return 0;
}