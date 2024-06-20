#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
unordered_map<int, string> umap = {{2, "abc"}, {3, "def"}, {4, "ghi"}, {5, "jkl"}, {6, "mno"}, {7, "pqrs"}, {8, "tuv"}, {9, "wxyz"}};
class Solution {
public:
    vector<string> res;
    string subres;
    void backtracing(int n, string& str, int index) {
        if (subres.size() == n)
            res.push_back(subres);
        string letter = umap[str[index] - '0'];
        for (int i = 0; i < letter.size(); i++) {
            subres = subres + letter[i];
            backtracing(n, str, index + 1);
            subres.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if (digits == "")
            return {};
        backtracing(digits.size(), digits, 0);
        return res;
    }
};
int main() {
    Solution sol;
    string digits = "2";
    sol.letterCombinations(digits);
    for (auto& x : sol.res)
        cout << x << "\n";
    return 0;
}
