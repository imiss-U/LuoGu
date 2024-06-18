/**
 * @file L78.cpp
 * @author zhangtengfei (20226472@stu.neu.edu.cn)
 * @brief 给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。
 * 说明：解集不能包含重复的子集。
 * 示例: 输入: nums = [1,2,3] 输出: [ [3],   [1],   [2],   [1,2,3],   [1,3],   [2,3],   [1,2],   [] ]
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
    void dfs(vector<int>& nums, int startindex){
        res.push_back(path);
        if (startindex >= nums.size()) // # 这两句 if 加不加都行
            return;
        for (int i = startindex; i < nums.size(); i++){
            path.push_back(nums[i]);
            dfs(nums, i + 1);
            path.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums){
        dfs(nums, 0);
        return res;
    }
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int tmp;
    vector<int> nums;
    while (cin >> tmp){
        nums.push_back(tmp);
    }
    Solution sol;
    sol.subsets(nums);
    for (auto& x : sol.res){
        for (auto y : x){
            cout << y << " ";
        }
        cout << "\n";
    }
    return 0;
}
