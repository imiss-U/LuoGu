// #include <iostream>
// #include <map>
// #include <vector>
// using namespace std;
// multimap<char, char> umap;
// vector<int> num;
// void f(string& str) {
//     for (int i = 0; i < str.size(); i++)
//         num[i] += umap.count(str[i]);
// }
// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(0), cout.tie(0);
//     string str;
//     long long res = 1;
//     int k;
//     cin >> str >> k;
//     char left, right;
//     for (int i = 0; i < k; i++) {
//         cin >> left >> right;
//         umap.insert({left, right});
//     }
//     num.resize(str.size(), 1);
//     f(str);
//     for (int i = 0; i < num.size(); i++) {
//         if (num[i] == 0)
//             continue;
//         else
//             res *= num[i];
//     }
//     cout << res;
//     return 0;
// }