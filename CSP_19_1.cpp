#include <iostream>
#include <vector>
using namespace std;

bool f(const vector<int>& x, const vector<int>& y, const vector<char>& type, int a, int b, int c, int len) {
    long long temp = x[0] * a + y[0] * b + c;
    for (int i = 1; i < len; i++) {
        if (((x[i] * a + y[i] * b + c) * temp > 0 && type[i] != type[0]) || (((x[i] * a + y[i] * b + c) * temp < 0) && type[i] == type[0]))
            return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> X(n), Y(n);
    vector<char> Type(n);

    for (int i = 0; i < n; i++)
        cin >> X[i] >> Y[i] >> Type[i];

    vector<int> A(m), B(m), C(m);
    for (int i = 0; i < m; i++) {
        cin >> C[i] >> A[i] >> B[i];
        if (f(X, Y, Type, A[i], B[i], C[i], n))
            cout << "Yes" << "\n";
        else
            cout << "No" << "\n";
    }
    return 0;
}