// ! 由此题得出：在Linux和Windows系统下的long字节是不一样的
// ! Linux下long是8字节，与long long一样（包括最大范围），而Windows下long与int最大值一样
#include <iostream>
using namespace std;
long long res[10000001];
int main() {
	ios::sync_with_stdio(false);
	int t, m;
	cin >> t >> m;
	int vol[10001], val[10001];
	for (int i = 1; i <= m; i++)
		cin >> vol[i] >> val[i];
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= t; j++) {
			if (j >= vol[i])
				res[j] = max(res[j], res[j - vol[i]] + val[i]);
		}
	}
	cout << res[t];
	return 0;
}
