/**
 * @file L39.cpp
 * @author zhangtengfei (20226472@stu.neu.edu.cn)
 * @brief 给定一个无重复元素的数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
 * candidates 中的数字可以无限制重复被选取。
 * 说明：
 * 所有数字（包括 target）都是正整数。
 * 解集不能包含重复的组合。
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
    int sum = 0;
    void dfs(vector<int>& candidates, int target, int startindex){
        if (sum > target)
            return;
        if (sum == target){
            res.push_back(path);
            return;
        }
        for (int i = startindex; i < candidates.size(); i++){
            path.push_back(candidates[i]);
            sum += candidates[i];
            dfs(candidates, target, i);// !数字可以重复选取 这里用i 不用 i + 1
            sum -= candidates[i];
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target){
        dfs(candidates, target, 0);
        return res;
    }
};
int main(){
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;
    Solution sol;
    sol.combinationSum(candidates, target);
    return 0;
}