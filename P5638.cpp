#include <iostream>
#include <vector>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n, k;
	cin >> n >> k;
	vector<long long> city(n+10);
	vector<long long> pre(n);
	for (int i = 1; i < n; i++) {
		cin >> city[i];
		pre[i] = pre[i - 1] + city[i];
	}
	if (k == 0) {
		cout << pre[n - 1] - pre[0];
		return 0;
	}
	long long Max = pre[k] - pre[0];
	for (int i = 1; i < n; i++) {
		if (pre[i + k] - pre[i] >= Max)
			Max = pre[i + k] - pre[i];
	}
	cout << pre[n - 1] - pre[0] - Max;
	return 0;
}
