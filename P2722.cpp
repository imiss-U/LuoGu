#include <iostream>
using namespace std;
int res[10001];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int m, n;
	cin >> m >> n;
	int vol[10001], awa[10001];
	for (int i = 1; i <= n; i++)
		cin >> awa[i] >> vol[i];
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			if (j >= vol[i])
				res[j] = max(res[j], res[j - vol[i]] + awa[i]);
		}
	}
	cout << res[m];
	return 0;
} 
