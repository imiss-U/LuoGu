#include <iostream>
using namespace std;
    int in[3];
    int n;
    int res[3];
    int sum = 0;
void dfs(int cur)
{
    if(cur == 10)
    {
        if(sum == n)
        {for(int i=0;i<n;i++)
            cout << res[i] << " ";
        cout << "\n";}
    }
    for(int i = 0;i<10;i++)
    {
        sum += in[i];
        dfs(cur+1);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin >> n;
    dfs(1);
    return 0;
}