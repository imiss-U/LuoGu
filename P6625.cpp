#include <iostream>
using namespace std;
long long pre[100005];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	int num[100005];
	for (int i = 1; i <= n; i++) {
		cin >> num[i];
		pre[i] = pre[i - 1] + num[i];
	}
	long long sum = 0;
	for (int i = 2; i <= n; i++) {
		if (pre[i] > 0)
			sum += pre[i];
	}
	cout << sum;
	return 0;
}
