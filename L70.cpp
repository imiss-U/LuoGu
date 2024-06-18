#include <iostream>
#include <vector>
using namespace std;
int res[40];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	int nums[2];
	nums[0] = 1;
	nums[1] = 2;
	res[0] = 1;
	for (int i = 1; i <= n; i++){
		for (int j = 0; j < 2; j++){
			if (i >= nums[j]){
				res[i] += res[i - nums[j]];
			}
		}
	}
	cout << res[n];
	return 0;
}
