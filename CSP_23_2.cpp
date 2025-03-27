#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
vector<int> factor, freq;
void breakdown(long long num) {
    for (int i = 2; i < sqrt(num); i++) {
        if (num % i == 0) {
            int tmp = 0;
            while (num % i == 0) {
                tmp++;
                num /= i;
            }
            factor.push_back(i);
            freq.push_back(tmp);
        }
    }
    if (num != 1) {
        factor.push_back(num);
        freq.push_back(1);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int q;
    cin >> q;
    vector<long long> N(q), K(q);
    for (int i = 0; i < q; i++) {
        cin >> N[i] >> K[i];
        breakdown(N[i]);
        for (auto it = freq.begin(); it != freq.end(); it++)
            if (*it < K[i])
                *it = 0;
        long long res = 1;
        for (int i = 0; i < factor.size(); i++)
            res *= pow(factor[i], freq[i]);
        cout << res << "\n";
        factor.clear();
        freq.clear();
    }
    return 0;
}