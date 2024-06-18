#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> S;
        for (auto i : nums1)
            S.insert(i);
        vector<int> res;
        for (auto j : nums2)
            if (S.find(j) != S.end())
                res.push_back(j);
        res.erase(unique(res.begin(), res.end()), res.end());
        return res;
    }
};
int main() {
    vector<int> nums1 = {9, 4, 9, 8, 4};
    vector<int> nums2 = {4, 9, 5};
    Solution S;
    vector<int> res = S.intersection(nums1, nums2);
    for (auto i : res)
        cout << i << " ";
    cout << endl;
    return 0;
}