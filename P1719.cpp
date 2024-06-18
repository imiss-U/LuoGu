#include <iostream>
#include <vector>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	vector<vector<int> > pre(n + 1, vector<int>(n + 1));
	vector<vector<int> > square(n, vector<int>(n));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n;j++)
			cin >> square[i][j];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1] + square[i - 1][j - 1];
	int Max = pre[1][1];
	for (int x1 = 0; x1 <= n; x1++) {
		for (int y1 = 0; y1 <= n; y1++) {
			for (int x2 = x1 + 1; x2 <= n; x2++) {
				for (int y2 = y1 + 1; y2 <= n; y2++) {
					if (pre[x2][y2] + pre[x1][y1] - pre[x1][y2] - pre[x2][y1] >= Max)
						Max = pre[x2][y2] + pre[x1][y1] - pre[x1][y2] - pre[x2][y1];
				}
			}
		}
	}
	cout << Max << "\n";
	return 0;
}
