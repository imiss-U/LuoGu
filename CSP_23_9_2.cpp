#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    vector<double> K(n + 1), thera(n + 1);
    K[0] = 1, thera[0] = 0;
    for (int i = 1; i <= n; i++) {
        int temp;
        double temp2;
        scanf("%d %lf", &temp, &temp2);
        if (temp == 1) {
            K[i] = K[i - 1] * temp2;
            thera[i] = thera[i - 1];
        }
        else {
            K[i] = K[i - 1];
            thera[i] = thera[i - 1] + temp2;
        }
    }

    for (int i = 0; i < m; i++) {
        int l, r;
        double x, y;
        scanf("%d %d %lf %lf", &l, &r, &x, &y);
        x = x * (K[r] / K[l - 1]);
        y = y * (K[r] / K[l - 1]);
        double orix = x, oriy = y;
        x = orix * cos(thera[r] - thera[l - 1]) - oriy * sin(thera[r] - thera[l - 1]);
        y = orix * sin(thera[r] - thera[l - 1]) + oriy * cos(thera[r] - thera[l - 1]);
        printf("%.3lf %.3lf\n", x, y);
    }
    return 0;
}