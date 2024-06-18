#include <iostream>
using namespace std;
int num[1001][1001];
int s[1001][1001];
int Max = -10000000;
int x, y;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int N, M, C;
	cin >> N >> M >> C;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> num[i][j];
			s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + num[i][j];
		}
	}
	for (int i = C; i <= N; i++) {
		for (int j = C; j <= M; j++) {
			if (s[i][j] - s[i - C][j] - s[i][j - C] + s[i - C][j - C] >= Max) {
				Max = s[i][j] - s[i - C][j] - s[i][j - C] + s[i - C][j - C];
				x = i - C;
				y = j - C;
			}
		}
	}
	cout << x + 1 << " " << y + 1;
	return 0;
}
