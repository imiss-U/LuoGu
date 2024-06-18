#include <iostream>
#include <vector>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int N;
	cin >> N;
	vector<int> num(N + 2);
	vector<int> pre(N + 2);
	for (int i = 1; i <= N; i++) {
		cin >> num[i];
		pre[i] = (pre[i - 1] + num[i]) % 7;
	}
	int len = 0, left = 0, right = 0;
	for (int i = 0; i <= N; i++) {
		if (pre[i] == 0) {
			left = i;
			break;
		}
	}
	for (int j = N; j >= 0; j--) {
		if (pre[j] == 0) {
			right = j;
			break;
		}
	}
	len = right - left;
	for (int k = 1; k <= 6; k++) {
		for (int i = 0; i <= N; i++) {
			if (pre[i] == k) {
				left = i;
				break;
			}
		}
		for (int j = N; j >= 0; j--) {
			if (pre[j] == k) {
				right = j;
				break;
			}
		}
		len = (len >= right - left) ? len : (right - left);
	}
	cout << len;
	return 0;
}
