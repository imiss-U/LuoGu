#include <iostream>
#include <vector>
using namespace std; 
long long sum = 0;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n, num[200005];
	cin >> n;
	vector<long long> pre(n + 1);
	for (int i = 0; i < n; i++) {
		cin >> num[i];
		if (i == 0)
			pre[0] = num[0];
		else
			pre[i] = pre[i - 1] + num[i];
	}
	for (int i = 0; i < n - 1; i++) {
		sum += num[i] * (pre[n - 1] - pre[i]);
	}
	cout << sum;
	return 0;
}
