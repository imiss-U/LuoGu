#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        v[i] = i + 1;
    do
    {
        for (int i = 0; i < n; i++)
        {
            cout.width(5);
            cout << v[i];
        }
        cout << "\n";
    } while (next_permutation(v.begin(), v.end()));
    return 0;
}