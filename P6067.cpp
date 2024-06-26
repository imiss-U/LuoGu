// * long long long long long long long long long long long long long long long !!!!!!
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int N;
    cin >> N;
    vector<long long> sound(N + 1);
    vector<long long> prex(N + 1);
    long long sum = 0;
    for (int i = 1; i <= N; i++)
        cin >> sound[i];
    sort(++sound.begin(), sound.end());
    for (int i = 1; i <= N; i++) {
        prex[i] = prex[i - 1] + sound[i];
    }
    for (int i = N; i >= 1; i--)
        sum += labs(prex[i - 1] - (i - 1) * sound[i]);
    cout << sum * 2;
    return 0;
}