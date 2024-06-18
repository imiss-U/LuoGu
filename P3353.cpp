#include <iostream>
#include <vector>
using namespace std;
int star[100005];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int N, W;
	cin >> N >> W;
	if (W == 0) {
		cout << 0;
		return 0;
	}
	int pos, light;
	for (int i = 0; i < N; i++)	{
		cin >> pos >> light;
		star[pos] += light;
	}
	vector<int> pre(N);
	pre[0] = star[0];
	for (int i = 1; i < N; i++)
		pre[i] = pre[i - 1] + star[i];
	int Max = pre[W] - pre[0] + star[0];
	for (int i = 1; i < N - W; i++) {
		int temp = pre[i + W] - pre[i];
		if (temp >= Max)
			Max = temp;
	}
	cout << Max;
	return 0;
}
