// ! 千万记得开 long long
#include <iostream>
#include <algorithm>
using namespace std;
int prim[1000];
long long res[1001];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n, k = 0;
	cin >> n;
	bool flag = false;
	for (int i = 2; i <= n; i++){
		for (int j = 2; j <= i - 1; j++){
			if (i % j == 0){
				flag = true;
				break;
			}
		}
		if (flag == false){
			prim[k] = i;
			k++;
		}
		flag = false;
	}
	int V = n, N = k;
	res[0] = 1;
	for (int i = 0; i < N; i++){
		for (int j = 1; j <= V; j++){
			if (j >= prim[i])
				res[j] += res[j - prim[i]];
		}
	}
	cout << res[V];
	return 0;
}
