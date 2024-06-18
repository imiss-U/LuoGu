// https://www.cnblogs.com/jcwy/p/18003097
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int min_time(int a[], int n)
{
    if (n == 1)
        return a[0];
    if (n == 2)
        return max(a[0], a[1]);
    int sum1 = 0, sum2 = 0, dis = 2e9;
    for (int i = 0; i < n; i++)
        sum2 += a[i];
    int count = 1 << n;
    vector<int> res(count);
    for (int i = 0; i < count; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if ((i >> j) & 1)
                res[i] += a[j];
        }
        if (abs(2 * res[i] - sum2) < dis)
        {
            dis = abs(2 * res[i] - sum2);
            sum1 = res[i];
        }
    }
    return max(sum1, sum2 - sum1);
}
int main()
{
    int s1, s2, s3, s4;
    cin >> s1 >> s2 >> s3 >> s4;
    int A[62], B[62], C[62], D[62];
    for (int i = 0; i < s1; i++)
        cin >> A[i];
    for (int i = 0; i < s2; i++)
        cin >> B[i];
    for (int i = 0; i < s3; i++)
        cin >> C[i];
    for (int i = 0; i < s4; i++)
        cin >> D[i];
    int ans = 0;
    ans += min_time(A, s1);
    ans += min_time(B, s2);
    ans += min_time(C, s3);
    ans += min_time(D, s4);
    cout << ans;
    return 0;
}