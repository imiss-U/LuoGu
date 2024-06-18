/*
	* 1. 首先，33~34行0的情况忘记特判了
	* 2. 其次，32行num3[0] = diff3[0]忘记加了
*/
#include <iostream>
#include <vector>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	vector<int> num1(n + 3), num2(n + 3), num3(n + 3);
	vector<int> diff1(n + 3), diff2(n + 3), diff3(n + 3);
	for (int i = 0; i < m; i++) {
		int left, right, color;
		cin >> left >> right >> color;
		if (color == 1) {
			diff1[left - 1]++;
			diff1[right]--;
		}
		if (color == 2) {
			diff2[left - 1]++;
			diff2[right]--;
		}
		if (color == 3) {
			diff3[left - 1]++;
			diff3[right]--;
		}
	}
	int ans = 0;
	num1[0] = diff1[0], num2[0] = diff2[0], num3[0] = diff3[0];
	if (num1[0] && num2[0] && (!num3[0]))
		ans++;
	for (int i = 1; i < n; i++) {
		num1[i] = num1[i - 1] + diff1[i];
		num2[i] = num2[i - 1] + diff2[i];
		num3[i] = num3[i - 1] + diff3[i];
		if (num1[i] && num2[i] && (!num3[i]))
			ans++;
	}
	cout << ans;
	return 0;
}
