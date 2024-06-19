#include <iostream>
#include <vector>
using namespace std;
class Solution{
public:
    vector<vector<int>> res;
    vector<int> path;
    void dfs(int n, int k, int startindex){
        if (path.size() == k){
            res.push_back(path);
            return;
        }
        for (int i = startindex; i <= n - (k - path.size()) + 1; i++){ // !这里从startindex开始，避免在数组中选取不重复数字时结果集中出现[2,4]和[4,2]重复的情况
            path.push_back(i);
            dfs(n, k, i + 1);
            path.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k){
        dfs(n, k, 1);
        return res;
    }
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n, k;
    cin >> n >> k;
    Solution sol;
    sol.combine(n, k);
    for (auto& x : sol.res){
        for (auto y : x){
            cout << y << " ";
        }
        cout << "\n";
    }
    return 0;
}
