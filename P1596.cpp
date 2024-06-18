// # 又是抄的题解~~~~~~
#include <iostream>
using namespace std;
int sum = 0;
const int x[8] = {1, -1, 0, 1, -1, 0, 1, -1};
const int y[8] = {1, -1, 1, 0, 0, -1, -1, 1};
bool flag[103][103];
char map[103][103];
void dfs(int startx, int starty) {
	flag[startx][starty] = true;
	for (int i = 0; i < 8; i++){
		if (map[startx + x[i]][starty + y[i]] == 'W' && flag[startx + x[i]][starty + y[i]] == false) {
			dfs(startx + x[i], starty + y[i]);
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int N, M;
	cin >> N >> M;	
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 1; i <= N; i++){
		for (int j = 1; j <=M; j++)
			if (map[i][j] == 'W' && flag[i][j] == false) {
				sum++;
				dfs(i, j);
			}
	}
	cout << sum;
	return 0;
} 
