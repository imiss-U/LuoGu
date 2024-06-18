#include <iostream>
#include <vector>

using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int N, total = 0;
    cin >> N;
    vector<int> student(N);
    for (int i = 0; i < N; i++) {
        cin >> student[i];
        total += student[i];
    }
    vector<int> f(total / 2 + 1);
    for (int i = 0; i < N; i++) {
        for (int j = total / 2 + 1; j > student[i]; j--) {
            f[j] = max(f[j], f[j - student[i]] + 1);
        }
    }
    for (int j = total / 2; j > 0; j--) {
        if (f[j] == N / 2) {
            cout << j;
            return 0;
        }
    }
}