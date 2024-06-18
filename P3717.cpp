#include <iostream>
#include <cmath>
using namespace std;
bool map[101][101];
int n;
void Visit(int x, int y, int r) {
	int up = (y - r >= 1) ? (y - r) : 1;
	int down = (y + r <= n) ? (y + r) : n;
	int left = (x - r >= 1) ? (x - r) : 1;
	int right = (x + r <= n) ? (x + r) : n;
	for (int i = left; i <= right; i++) {
		for (int j = up; j <= down; j++) {
			if (hypot(x - i, y - j) <= r) 
				map[i][j] = true;
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int m, r;
	cin >> n >> m >> r;
	int X[101], Y[101];
	for (int i = 0; i < m; i++) {
		cin >> X[i] >> Y[i];
		Visit(X[i], Y[i], r);
	}
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (map[i][j] == true)
				sum ++;
		}
	}
	cout << sum;
	return 0;
}
