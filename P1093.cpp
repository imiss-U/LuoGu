#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;
using mytuple = tuple<int, int, int>;
bool cmp(mytuple m1, mytuple m2)
{
    if (get<0>(m1) > get<0>(m2))
        return true;
    else if (get<0>(m1) < get<0>(m2))
        return false;
    else
    {
        if (get<1>(m1) > get<1>(m2))
            return true;
        else if (get<1>(m1) < get<1>(m2))
            return false;
        else
            return get<2>(m1) < get<2>(m2);
    }
}
int main()
{
    int n, a, b, c;
    cin >> n;
    mytuple temp;
    vector<mytuple> n1;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b >> c;
        temp = make_tuple(a + b + c, a, i + 1);
        n1.push_back(temp);
    }
    sort(n1.begin(), n1.end(), cmp);
    vector<mytuple>::iterator it = n1.begin();
    for (int i = 0; i < 5; i++)
    {
        cout << get<2>(*it) << " " << get<0>(*it) << "\n";
        it++;
    }
    return 0;
}