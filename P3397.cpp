// * 你研究了无数天的二位差分……
// * 还有一个问题就是数组得开到1002，1001就会报错。别问我，我也不知道为什么
#include <iostream>
using namespace std;
int carpet[1002][1002];
int diff[1002][1002];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int N ,M;
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			diff[i][j] = carpet[i][j] - carpet[i - 1][j] - carpet[i][j - 1] + carpet[i - 1][j - 1];
		}
	}
	int x1, y1, x2, y2;
	for (int k = 0; k < M; k++) {
		cin >> x1 >> y1 >> x2 >> y2;
		diff[x1][y1]++;
		diff[x2 + 1][y1]--;
		diff[x1][y2 + 1]--;
		diff[x2 + 1][y2 + 1]++;
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			diff[i][j] = diff[i][j] + diff[i - 1][j] + diff[i][j - 1] - diff[i - 1][j - 1];
			carpet[i][j] = diff[i][j];
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cout << carpet[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}
