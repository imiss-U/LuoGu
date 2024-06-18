#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main()
{
    int m, temp;
    vector<int> n;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> temp;
        n.push_back(temp);
    }
    sort(n.begin(), n.end());
    for (auto i : n)
        cout << i << " ";
    cout << "\n";
    return 0;
}