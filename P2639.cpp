#include <iostream>
using namespace std;
int volum[45001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int V, N;
	cin >> V >> N;
	int num[501];
	for (int i = 0; i < N; i++)
		cin >> num[i];
	for (int i = 0; i < N; i++) {
		for (int j = V; j >= num[i]; j--) {
			volum[j] = max(volum[j], volum[j - num[i]] + num[i]);
		}
	}
	cout << volum[V];
	return 0;
}
