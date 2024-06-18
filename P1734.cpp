// * 二刷时 卡时间复杂度了 求约数和算法未优化
// * 但也不完全是 比如19行那里没加等号……
#include <iostream>
using namespace std;
int a[1001];
int f[1001];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int S;
	cin >> S;
	for (int j =2; j < S; j++){
		for (int i = 1; i < j; i++){
			if (j % i == 0)
				a[j] += i;
		}
	}
	for (int i = 2; i < S; i++){
		for (int j = S; j >= i; j--){
			f[j] = max(f[j], f[j - i] + a[i]);
		}
	}
	cout << f[S];
	return 0;
} 
