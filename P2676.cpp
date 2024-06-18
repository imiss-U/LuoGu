#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int N, S = 0, B;
    cin >> N >> B;
    vector<int> n;
    for (int i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;
        n.push_back(temp);
    }
    sort(n.rbegin(), n.rend());
    int res = 0;
    while (S < B)
    {
        S += n[res];
        res++;
    }
    cout << res;
    return 0;
}