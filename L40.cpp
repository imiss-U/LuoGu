#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution{
public:
    vector<vector<int>> res;
    vector<int> path;
    int sum = 0;
    void dfs(vector<int>& canditates, int target, int startindex){
        if (sum > target)
            return;
        if (sum == target){
            res.push_back(path);
            return;
        }
        for (int i = startindex; i < canditates.size(); i++){
            if (i > startindex && canditates[i] == canditates[i - 1]) // ! 这两个条件的顺序不能互换 否则会报错
                continue;
            path.push_back(canditates[i]);
            sum += canditates[i];
            dfs(canditates, target, i + 1);
            sum -= canditates[i];
            path.pop_back();
        }
    }
    vector<vector<int>> f(vector<int>& canditates, int target){
        sort(canditates.begin(), canditates.end());
        dfs(canditates, target, 0);
        return res;
    }
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    vector<int> nums;
    int target, tmp;
    cin >> target;
    while (cin >> tmp)
        nums.push_back(tmp);
    sort(nums.begin(), nums.end());
    Solution sol;
    sol.f(nums, target);
    for (auto& x : sol.res){
        for (auto y : x){
            cout << y << " ";
        }
        cout << "\n";
    }
    return 0;
}
