/**
 * @file L77.cpp
 * @author zhangtengfei (20226472@stu.neu.edu.cn)
 * @brief 给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。
 * 示例: 输入: n = 4, k = 2 输出: [ [2,4], [3,4], [2,3], [1,2], [1,3], [1,4], ]
 * @version 0.1
 * @date 2024-03-12
 *
 *
 */
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
