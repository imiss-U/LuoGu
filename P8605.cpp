#include <iostream>
#include <vector>

using namespace std;
vector<vector<int>> res;
vector<int> path;

void dfs(vector<vector<int>>& graph, int i) {
    // if ()
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int M, N;
    cin >> N >> M;
    vector<vector<int>> graph(N + 1, vector<int>(N + 1));
    for (int i = 0; i < M; i++) {
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        graph[tmp1][tmp2] = 1;
    }
    dfs(graph, 1);
    cout << res.size();
    return 0;
}