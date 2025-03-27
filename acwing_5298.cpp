#include <cstdio>
#include <cmath>
using namespace std;
int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int K;
    double theta;
    double p[100001], q[100001];
    p[0] = 1, q[0] = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d %lf", &K, &theta);
        if (K == 1) {
            p[i] = theta * p[i - 1];
            q[i] = q[i - 1];
        }
        else {
            p[i] = p[i - 1];
            q[i] = theta + q[i - 1];
        }
    }
    int i, j;
    double x, y;
    for (int k = 1; k <= m; k++) {
        scanf("%d %d %lf %lf", &i, &j, &x, &y);
        double pp = p[j] / p[i - 1];
        double qq = q[j] - q[i - 1];
        double X = x * cos(qq) - y * sin(qq);
        double Y = x * sin(qq) + y * cos(qq);
        X *= pp, Y *= pp;
        printf("%.3lf %.3lf\n", X, Y);
    }
    return 0;
}