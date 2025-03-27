#include <iostream>
#include <vector>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int> operatex(n), operatey(n), positionx(m), positiony(m);
    for (int i = 0; i < n; i++) {
        cin >> operatex[i] >> operatey[i];
    }
    for (int j = 0; j < m; j++) {
        cin >> positionx[j] >> positiony[j];

        for (int i = 0; i < n; i++) {
            positionx[j] += operatex[i];
            positiony[j] += operatey[i];
        }
        cout << positionx[j] << " " << positiony[j] << endl;
    }
    return 0;
}