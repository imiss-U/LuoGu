// * 李思睿！！！
#include <cstdio>
int len[10010];
int a[5001];
int main()
{
    int N;
    long long ans = 0;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &len[i]);
    }
    for (int i = 0; i < N; i++)
        a[len[i]]++;
    for (int edge = 5000; edge >= 2; edge--)
    {
        if (a[edge] >= 2)
        {
            for (int i = 1; i <= edge / 2; i++)
            {
                if (i * 2 < edge)
                {
                    ans += a[i] * a[edge - i] * a[edge] * (a[edge] - 1) / 2;
                }
                else if (i * 2 == edge)
                {
                    ans += a[i] * (a[i] - 1) * a[edge] * (a[edge] - 1) / 4;
                }
            }
        }
        else
            continue;
    }
    printf("%d", ans % 1000000007);
    return 0;
}