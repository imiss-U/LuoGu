#include <iostream>
using namespace std;
bool visit[10];
int main()
{
    bool flag = false;
    int A, B, C;
    cin >> A >> B >> C;
    int a, b, c;
    int d, e, f;
    int g, h, i;
    for (a = 1; a <= 9; a++)
    {
        visit[a] = true;
        for (b = 1; b <= 9; b++)
        {
            if (visit[b])
                continue;
            visit[b] = true;
            for (c = 1; c <= 9; c++)
            {
                if (visit[c])
                    continue;
                visit[c] = true;
                for (d = 1; d <= 9; d++)
                {
                    if (visit[d])
                        continue;
                    visit[d] = true;
                    for (e = 1; e <= 9; e++)
                    {
                        if (visit[e])
                            continue;
                        visit[e] = true;
                        for (f = 1; f <= 9; f++)
                        {
                            if (visit[f])
                                continue;
                            visit[f] = true;
                            for (g = 1; g <= 9; g++)
                            {
                                if (visit[g])
                                    continue;
                                visit[g] = true;
                                for (h = 1; h <= 9; h++)
                                {
                                    if (visit[h])
                                        continue;
                                    visit[h] = true;
                                    for (i = 1; i <= 9; i++)
                                    {
                                        if (visit[i])
                                            continue;
                                        visit[i] = true;
                                        if ((a * 100 + b * 10 + c) * B == (d * 100 + e * 10 + f) * A && (a * 100 + b * 10 + c) * C == (g * 100 + h * 10 + i) * A)
                                        {
                                            flag = true;
                                            cout << a << b << c << " " << d << e << f << " " << g << h << i << "\n";
                                        }
                                        visit[i] = false;
                                    }
                                    visit[h] = false;
                                }
                                visit[g] = false;
                            }
                            visit[f] = false;
                        }
                        visit[e] = false;
                    }
                    visit[d] = false;
                }
                visit[c] = false;
            }
            visit[b] = false;
        }
        visit[a] = false;
    }
    if (!flag)
        cout << "No!!!";
    return 0;
}