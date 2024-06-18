#include <iostream>
#include <vector>
using namespace std;
vector <int> res(10000, INT_MAX);
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	int nums[101];
	for (int i = 1; i <= 100; i++)
		nums[i] = i * i;
	res[0] = 0;
	for (int i = 1; i <= 100; i++){
		for (int j = nums[i]; j <= n; j++){
			res[j] = min(res[j], res[j - nums[i]] + 1);
		}
	}
	cout << res[n];
	return 0;
}
