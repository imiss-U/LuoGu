#include <iostream> 
using namespace std;
int value[101], cost[101];
int res[250000000];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int N, H;
	cin >> N >> H;
	for (int i = 0; i < N; i++)
		cin >> value[i] >> cost[i];
	for (int i = 0; i < N; i++) {
		for (int j = cost[i]; j <= H + 10000; j++)
			res[j] = max(res[j], res[j - cost[i]] + value[i]);
	}
	for (int j = 0; j < 250000000; j++) {
		if (res[j] >= H) {
			cout << j;
			break;
		}
	}
	return 0;
}
