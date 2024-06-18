#include <iostream>
using namespace std;
int v[1010];
bool flag[1010];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int T, M;
    cin >> T >> M;
    int c[1010], w[100];
    for (int i = 0; i < M; i++)
        cin >> c[i] >> w[i];
    for (int i = 0; i < M; i++){
        for (int j = T; j >= c[i]; j--)
        {
            v[j] = max(v[j], v[j - c[i]] + w[i]);
            if(v[j] == v[j - c[i]] + w[i])
                flag[i] = true;
        }
    }
    cout << v[T] << "\n";
    for(int i = 0; i < M; i++)
    {
        if(flag[i])
            cout << c[i] << "  ";
    }
    return 0;
}