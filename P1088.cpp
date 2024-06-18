#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int N, M;
    cin >> N >> M;
    vector<vector<int>> v(110, vector<int>(N));
    for (int i = 0; i < N; i++)
    {
        cin >> v[0][i];
        v[1][i] = v[0][i];
    }
    int j = 1;
    do
    {
        for (int k = 0; k < N; k++)
            v[j][k] = v[1][k];
        j++;
    } while (next_permutation(v[1].begin(), v[1].end()) && j < 109);
    for (int i = 0; i < N; i++)
        cout << v[1 + M][i] << " ";
    return 0;
}