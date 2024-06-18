#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;
int v, g;
int vit[26];
int cat[16][26];
vector<int> current(26);
vector<vector<int>> res;
vector<int> path;
bool cmp(vector<int>& m1, vector<int>& m2) {
	if (m1.size() < m2.size())
		return true;
	if (m1.size() > m2.size())
		return false;
	return m1 < m2;
}
bool meet() {
	for (int i = 0; i < v; i++){
		if (current[i] < vit[i])
			return false;
	}
	return true;
}
void addVit(int k) {
	for (int i = 0; i < v; i++) {
		current[i] += cat[k][i];
	}
}
void minVit(int k) {
	for (int i = 0; i < v; i++) {
		current[i] -= cat[k][i];
	}
}
void dfs(int v, int g, int startindex) {
	if (meet()) {
		res.push_back(path);
		return;
	}
	for (int i = startindex; i <= g; i++) {
		addVit(i);
		path.push_back(i);
		dfs(v, g, i + 1);
		path.pop_back();
		minVit(i);
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> v;
	for (int i = 0; i < v; i++)
		cin >> vit[i];
	cin >> g;
	for (int i = 1; i <= g; i++) {
		for (int j = 0; j < v; j++) 
			cin >> cat[i][j];
	}
	dfs(v, g, 1);
	sort(res.begin(), res.end(), cmp);
	cout << res[0].size() << " ";
	sort(res[0].begin(), res[0].end());
	for (auto x : res[0])
		cout << x << " ";
	return 0;
}
