#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	string str;
	for (int i = 1; i <= 1000; i++) {
		for (int k = 0; k < i; k++)
			str += to_string(i);
	}
	vector<int> pre(1000000);
	pre[0] = 1;
	for (int i = 1; i < str.size() && i < 1000000; i++)
		pre[i] = pre[i - 1] + str[i] - '0';
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int l, r;
		cin >> l >> r;
		cout << pre[r - 1] - pre[l - 1] + str[l - 1] - '0' << "\n";
	}
	return 0;
}
