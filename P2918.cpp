#include <iostream>
using namespace std;
int weight[109], cost[109];
int res[55009];
int Min = 200000000;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int N, H;
	cin >> N >> H;
	for (int i = 0; i < N; i++) 
		cin >> weight[i] >> cost[i];
	for (int i = 1; i < 55009; i++)
		res[i] = 200000000;
	for (int i = 0; i < N; i++) {
		for (int j = weight[i]; j <= H + 5000; j++)
			res[j] = min(res[j], res[j - weight[i]] + cost[i]);
	}
	for (int i = H; i <= H + 5000; i++)
		Min = min(Min, res[i]);
	cout << Min;
	return 0;
}
