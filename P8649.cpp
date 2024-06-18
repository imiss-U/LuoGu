// # 抄的题解  有关同余的部分
// # bucket数组不开long long 第三个测试点过不了
#include <iostream>
#include <vector>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int N, K;
	cin >> N >> K;
	vector<int> num(N + 3);
	vector<long long> pre(N + 3);
	vector<int> bucket(K);
	bucket[0] = 1;
	for (int i = 1; i <= N; i++) {
		cin >> num[i];
		pre[i] = pre[i - 1] + num[i];
		bucket[pre[i] % K]++;
	}
	long long res = 0;
	for (int i = 0; i < K; i++)
		res += bucket[i] * (bucket[i] - 1) / 2;
	cout << res;
	return 0;
}
