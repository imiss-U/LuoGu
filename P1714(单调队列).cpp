#include <iostream>
#include <vector>
#include <deque>
#include <climits>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int> A(n + 1), Sum(n + 1);
    
    // 构建前缀和
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
        Sum[i] = Sum[i - 1] + A[i];
    }
    
    // 使用单调队列优化
    deque<int> q;
    q.push_back(0);
    int Max = INT_MIN;  // 初始化为最小值
    
    for (int i = 1; i <= n; i++) {
        // 维护窗口大小不超过m
        while (!q.empty() && i - q.front() > m) {
            q.pop_front();
        }
        
        // 更新最大子段和
        Max = max(Max, Sum[i] - Sum[q.front()]);
        
        // 维护单调性
        while (!q.empty() && Sum[q.back()] >= Sum[i]) {
            q.pop_back();
        }
        q.push_back(i);
    }
    
    cout << Max << "\n";
    return 0;
}