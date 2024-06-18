#include <iostream>
using namespace std;
int f[401][401];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int h, t, n;
	int vol[51], wei[51], ene[51];
	cin >> h >> t >> n;
	for (int i =0; i< n; i++){
		cin >> vol[i] >> wei[i] >> ene[i];
	}
	for (int i = 1; i <= n; i++){
		for (int j = h; j >= vol[i]; j--){
			for (int k = t; k >= wei[i]; k--){
				f[j][k] = max(f[j][k], f[j - vol[i]][k - wei[i]] + ene[i]);
			}
		}
	}
	cout << f[h][t];
	return 0;
}
