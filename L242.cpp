#include <iostream>
#include <set>
using namespace std;
class Solution {
public:
    bool isAnagram(string s, string t) {
        multiset<char> S;
        for (auto i : s)
            S.insert(i);
        for (auto i : t)
            S.erase(S.find(i));
        if (S.empty())
            return true;
        else
            return false;
    }
};
int main() {
    Solution s;
    cout << s.isAnagram("anagram", "nagaram") << endl;
    return 0;
}