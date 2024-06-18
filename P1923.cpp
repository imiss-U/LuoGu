#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    int m, n;
    cin >> n >> m;
    vector<long long> n1;
    for (int i = 0; i < n; i++)
    {
        long long temp;
        cin >> temp;
        n1.push_back(temp);
    }
    sort(n1.begin(), n1.end());
    cout << n1.at(m);
    return 0;
}