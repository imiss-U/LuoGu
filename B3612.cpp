#include <iostream>
#include <vector>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n;
	vector<int> num(n);
	vector<int> pre(n);
	for (int i = 0; i < n; i++) {
		cin >> num[i];
		if (i == 0)
			pre[i] = num[i];
		else
			pre[i] = pre[i - 1] + num[i];
	}
	cin >> m;
	for(int i = 0; i < m; i++) {
		int left, right;
		cin >> left >> right;
		cout << pre[right - 1] - pre[left - 1] + num[left - 1] << "\n";
	}
	return 0;
}
