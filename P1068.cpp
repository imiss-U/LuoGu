#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <cmath>
using namespace std;
using mypair = pair<string, int>;
bool cmp(mypair m1, mypair m2)
{
    return m1.second > m2.second ? true : (m1.second < m2.second ? false : (m1.first < m2.first));
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<mypair> grade;
    for (int i = 0; i < n; i++)
    {
        string str;
        int temp;
        cin >> str >> temp;
        mypair mp = make_pair(str, temp);
        grade.push_back(mp);
    }
    sort(grade.begin(), grade.end(), cmp);
    int line = grade[floor(m * 1.5) - 1].second; // # 注意：这里需要减一，但我也没弄懂是为什么（也没调试），否则第二、三个测试点过不去
    cout << line << " ";
    int num = 0;
    for (auto &y : grade)
    {
        if (y.second >= line)
            num++;
        else
            break;
    }
    cout << num << "\n";
    for (auto x = grade.begin(); (*x).second >= line; x++)
    {
        cout << (*x).first << " " << (*x).second << "\n";
    }
    return 0;
}