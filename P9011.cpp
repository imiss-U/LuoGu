#include <iostream>
using namespace std;
int Cow[101];
int S[21], T[21], C[21], A[11], B[11], P[11], m[11];
int TIME = 0, tmp = 200000;
bool Fit(int N) {
	for (int s = 0; s < N; s++) {
		for (int i = S[s]; i <= T[s]; i++) {
			if (Cow[i] < C[s])
				return false;
		}
	}
	return true;
}
void addTIME(int k) {
	for (int i = A[k]; i <= B[k]; i++) {
		Cow[i] += P[k];
	}
}
void minTIME(int k) {
	for (int i = A[k]; i <= B[k]; i++) {
		Cow[i] -= P[k];
	}
}
void dfs(int N, int M, int startindex) {
	if (tmp > TIME && Fit(N)) {
		tmp = TIME;
		return;
	}
	for (int i = startindex; i < M; i++) {
		TIME += m[i];
		addTIME(i);
		dfs(N, M, i + 1);
		minTIME(i);
		TIME -= m[i];
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> S[i] >> T[i] >> C[i];
	for (int i = 0; i < M; i++)
		cin >> A[i] >> B[i] >> P[i] >> m[i];
	dfs(N, M, 0);
	cout << tmp;
	return 0;
}