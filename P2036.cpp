#include <iostream>
#include <vector>
#include <utility>
using namespace std;
using mypair = pair<int, int>;
int main()
{
    int N;
    cin >> N;
    int in[10][2];
    int num1 = 1, num2 = 0;
    int dis = 1e9;
    for (int i = 0; i < N; i++)
    {
        cin >> in[i][0] >> in[i][1];
    }
    int count = 1 << N;
    vector<mypair> res(count);
    for (int i = 0; i < count; i++)
        res[i].first = 1;
    for (int i = 0; i < count; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if ((i >> j) & 1)
            {
                res[i].first *= in[j][0];
                res[i].second += in[j][1];
            }
        }
        if (abs(res[i].first - res[i].second) <= dis && (res[i].first != 1 && res[i].second != 0))
            dis = abs(res[i].first - res[i].second);
    }
    cout << dis;
    return 0;
}