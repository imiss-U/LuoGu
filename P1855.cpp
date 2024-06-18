#include <iostream>
using namespace std;
int volum1[109], volum2[109], res[209][209];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int N, M, T;
	cin >> N >> M >> T;
	for (int i = 0; i < N; i++)
		cin >> volum1[i] >> volum2[i];
	for (int i = 0; i < N; i++) {
		for (int j = M; j >= volum1[i]; j--) {
			for (int k = T; k >= volum2[i]; k--)
				res[j][k] = max(res[j][k], res[j - volum1[i]][k - volum2[i]] + 1);
		}
	}
	cout << res[M][T];
	return 0;
}
