#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
    int n, m, temp;
    cin >> n >> m;
    vector<int> n1;
    for (int i = 0; i < m; i++)
    {
        cin >> temp;
        n1.push_back(temp);
    }
    sort(n1.begin(), n1.end());
    for (auto i : n1)
        cout << i << " ";
    return 0;
}