#include <iostream>
using namespace std;
struct People
{
    int mode;
    string name;
};

int n, m;
int Position(int com[][2], People people[])
{
    int cur = 0;
    for (int i = 0; i < m; i++)
    {
        if (com[i][0] == people[cur].mode)
            cur = (cur - com[i][1] + n) % n;
        else
            cur = (cur + com[i][1]) % n;
    }
    return cur;
}
int main()
{
    cin >> n >> m;
    People peo[100000];
    for (int i = 0; i < n; i++)
    {
        cin >> peo[i].mode >> peo[i].name;
    }
    int command[100000][2];
    for (int j = 0; j < m; j++)
    {
        cin >> command[j][0] >> command[j][1];
    }
    int pos = Position(command, peo);
    pos = pos % n;
    cout << peo[pos].name << "\n";
    return 0;
}