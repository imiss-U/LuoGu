#include <iostream>
using namespace std;
int sum[101];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	int heap[101];
	for (int i = 1; i <= n; i++)
		cin >> heap[i];
	for (int i = 1; i <= n; i++) {
		sum[i] = sum[i - 1] + heap[i];
		if (sum[i] >= 1000000000)
			sum[i] -= 1000000000;
	}
	if (sum[n] % 2 == 0)
		cout << "Bob";
	else
		cout << "Alice";
	return 0;
}
