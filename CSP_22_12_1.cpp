#include <cmath>
#include <cstdio>
using namespace std;
int main() {
    int n;
    double i;
    scanf("%d %lf", &n, &i);
    double sum = 0;
    for (int j = 0; j < n + 1; j++) {
        int tmp;
        scanf("%d", &tmp);
        sum += tmp / pow(1 + i, j);
    }
    printf("%.3lf", sum);
    return 0;
}