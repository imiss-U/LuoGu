// #include <iostream>
// #include <set>
// using namespace std;
// struct Field {
//     int cost;
//     int resource;
//     bool operator<(const Field& f) const {
//         return cost < f.cost;
//     }
// };
// int main() {
//     ios::sync_with_stdio(0);
//     cin.tie(0), cout.tie(0);
//     int n, m, k;
//     cin >> n >> m >> k;
//     long long total = 0;
//     Field f;
//     multiset<Field> fields;
//     for (int i = 0; i < n; i++) {
//         cin >> f.cost >> f.resource;
//         total += f.resource;
//         fields.insert(f);
//     }
//     long long maxResource = 0;
//     for (auto& it : fields)
//         maxResource += (it.cost - fields.begin()->cost) * it.resource;
    
//     if (maxResource <= m) {
//         m -= maxResource;
//         int tmp = fields.begin()->cost;
//         while (m >= total && tmp > k) {
//             m -= total;
//             tmp--;
//         }
//         cout << tmp;
//         return 0;
//     }
//     else {
        
//     }
// }
#include<bits/stdc++.h>
#include<iostream>
using namespace std;
 
int n, k;
long long int m;
map<int, int>tim, res, flag;
 
int main(){
    cin >> n >> m >> k;
 
    int max = 0;
    for(int i = 0; i < n; ++i){
        cin >> tim[i] >> res[i];
        max = max > tim[i] ? max : tim[i];
        flag[tim[i]] += res[i];     
        // flag[i]为用时i天的区域缩短一天所用时
    }
    for(int i = max; i > 0; i--){
        //cout << i << " " << flag[i] << endl;
        if(max == k)break;
        if(m > flag[i]){
            m = m - flag[i];
            flag[i - 1] += flag[i];
            max--;
        }else break;
    }
    cout << max;
    return 0;
}