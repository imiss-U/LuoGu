#include <iostream>
#include <algorithm>
using namespace std;
int res1[51];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	for (int p = 0; p < 51; p++)
		res1[p] = 100;
	res1[0] = 0;
	int n, m, k, r;
	cin >> n >> m >> k >> r;
	int Ti[11], homework[11], Scores[51];
	for (int i = 1; i <= n; i++)
		cin >> Ti[i];
	for (int i = 1; i <= m; i++)
		cin >> homework[i];
	for (int i = 1; i <= m; i++)
		cin >> Scores[i];
	for (int i = 1; i <= m; i++){
		for (int j = k; j >= Scores[i]; j--)
			res1[j] = min(res1[j], res1[j - Scores[i]] + homework[i]);
	}
	int V = r - res1[k];
	int sum = 0;
	int pos = 0;
	sort(Ti, Ti + n);
	while (V - Ti[pos] >= 0 && pos < n){
		V -= Ti[pos];
		sum++;
		pos++;
	}
	cout << sum;
	return 0;
}
