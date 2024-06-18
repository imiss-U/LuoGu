#include <cstdio>

int n, m;
void show(char ch[][100], int r, int s)
{
    if (ch[r][s] == '*')
    {
        printf("*");
        return;
    }
    else
    {
        int lei = 0;
        if (r - 1 >= 0 && ch[r - 1][s] == '*')
            lei++;
        if (r + 1 < n && ch[r + 1][s] == '*')
            lei++;
        if (s - 1 >= 0 && ch[r][s - 1] == '*')
            lei++;
        if (s + 1 < m && ch[r][s + 1] == '*')
            lei++;
        if (r - 1 >= 0 && s - 1 >= 0 && ch[r - 1][s - 1] == '*')
            lei++;
        if (r - 1 >= 0 && s + 1 < m && ch[r - 1][s + 1] == '*')
            lei++;
        if (r + 1 < n && s - 1 >= 0 && ch[r + 1][s - 1] == '*')
            lei++;
        if (r + 1 < n && s + 1 < m && ch[r + 1][s + 1] == '*')
            lei++;
        printf("%d",lei);
        return;
    }
}
int main()
{
    scanf("%d %d", &n, &m);
    char ch[100][100];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            scanf(" %c", &ch[i][j]);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            show(ch, i, j);
        printf("\n");
    }
    return 0;
}