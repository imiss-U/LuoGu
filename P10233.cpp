#include <iostream>
#include <vector>
using namespace std;
int match(char s) {
	if (s == 'P')
		return 3;
	if (s == 'p')
		return 2;
	if (s == 'G')
		return 1;
	return 0;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	while(T--) {
		string str;
		cin >> str;
		vector<int> pre(str.length());
		int data;
		cin >> data;
		pre[0] = match(str[0]);
		for (int i = 1; i < str.length(); i++)
			pre[i] = pre[i - 1] + match(str[i]);
		int left, right;
		for (int i = 0; i < data; i++) {
			cin >> left >> right;
			cout << pre[right - 1] - pre[left - 1] + match(str[left - 1]) << "\n";
		}
	}
	return 0;
}
