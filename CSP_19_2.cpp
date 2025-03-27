#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    int n, a, b;
    cin >> n >> a >> b;
    
    long long res = 0;
    vector<long long> A(a), Adata(a), B(b), Bdata(b);
    
    for (int i = 0; i < a; i++)
        cin >> A[i] >> Adata[i];
    for (int i = 0; i < b; i++)
        cin >> B[i] >> Bdata[i];
    
    int indexA = 0, indexB = 0;
    
    while (indexA < a && indexB < b) {
        if (A[indexA] < B[indexB]) {
            indexA++;
        } else if (A[indexA] > B[indexB]) {
            indexB++;
        } else {
            res += Adata[indexA] * Bdata[indexB];
            indexA++;
            indexB++;
        }
    }
    
    cout << res;
    return 0;
}