#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
vector<int> fetch;
bool complete = false;
int prim[5000];
void Store(int N) {
    prim[0] = 2;
    prim[1] = 3;
    prim[2] = 5;
    prim[3] = 7;
    prim[4] = 11;
    prim[5] = 13;
    prim[6] = 17;
    prim[7] = 19;
    prim[8] = 23;
    prim[9] = 29;
    prim[10] = 31;
    prim[11] = 37;
    prim[12] = 41;
    prim[13] = 43;
    prim[14] = 47;
    prim[15] = 53;
    prim[16] = 59;
    prim[17] = 61;
    prim[18] = 67;
    prim[19] = 71;
    prim[20] = 73;
    prim[21] = 79;
    prim[22] = 83;
    prim[23] = 89;
    prim[24] = 97;
    prim[25] = 101;
    int k = 26;
    if (N <= 101)
        return;
    for (int i = 102; i <= N; i++) {
        bool flag = false;
        for (int j = 2; j <= sqrt(i); j++) {
            if (i % j == 0) {
                flag = true;
                break;
            }
        }
        if (flag == false)
            prim[k++] = i;
    }
}
int Sum(vector<int>& m) {
    if (m.size() == 0)
        return 0;
    if (m.size() == 1)
        return m[0];
    return m[0] + m[1];
}
void dfs(int N, int startindex) {
    if (fetch.size() > 2)
        return;
    if (Sum(fetch) == N) {
        complete = true;
        return;
    }
    for (int i = startindex; prim[i] <= N - Sum(fetch); i++) {
        fetch.push_back(prim[i]);
        dfs(N, i);
        if (complete == true)
            return;
        fetch.pop_back();
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int N;
    cin >> N;
    Store(N);
    for (int i = 4; i <= N; i += 2) {
        dfs(i, 0);
        cout << i << "=" << fetch[0] << "+" << fetch[1] << "\n";
        fetch.clear();
        complete = false;
    }
    return 0;
}
