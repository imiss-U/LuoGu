#include <iostream>
using namespace std;
int res[12881];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int N, M;
	cin >> N >> M;
	int vol[3403], val[3403];
	for (int i = 1; i <= N; i++)
		cin >> vol[i] >> val[i]; 
	for (int i = 1; i <= N; i++)
		for (int j = M; j >= vol[i]; j--)
			res[j] = max(res[j], res[j - vol[i]] + val[i]);
	cout << res[M];
	return 0;
}
