#include <iostream>
#include <map>
using namespace std;
map<int, long long> mymap;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int N, C;
    cin >> N >> C;
    int temp;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        if (mymap.contains(temp))
            mymap.at(temp)++;
        else
            mymap.insert({temp, 1});
    }
    long long res = 0;
    for (auto it = mymap.begin(); it != mymap.end(); it++) {
        if (mymap.find(it->first + C) == mymap.end())
            continue;
        else
            res += it->second * mymap.find(it->first + C)->second;
    }
    cout << res;
    return 0;
}