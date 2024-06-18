#include <iostream>
using namespace std;
int res[1001][1001];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int N, M, X;
	cin >> N >> M >> X;
	int A[101], B[101], C[101];
	for (int i = 1; i <= N; i++)
		cin >> A[i] >> B[i] >>  C[i];
	for (int i = 1; i <= N; i++){
		for (int j = M; j >= B[i]; j--){
			for (int k = X; k >=C[i]; k--)
				res[j][k] = max(res[j][k], res[j - B[i]][k - C[i]] + A[i]);
		}
	}
	cout << res[M][X];
	return 0;
}
