#include <iostream>
using namespace std;
int res[5001];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int data1, data2, m, n;	// # wky能力值、老王能力值、题目总数、知识点总数 
	cin >> data1 >> data2 >> m >> n;
	int knowledge[5001];	// # 第i个知识点所需时间 
	for (int i = 1; i <= n; i++)
		cin >> knowledge[i];
	int paper[5001], reward[5001];// # 所属知识点、奖励
	for (int i = 1; i<= m; i++)
		cin >> paper[i] >> reward[i];
	int T;	// # 规定时间
	cin >> T;
	for (int i = 1; i <= n; i++)
		knowledge[i] = data2 / data1 * knowledge[i];
	for (int i = 1; i <= m; i++){
		for (int j = T; j >= knowledge[paper[i]]; j--){
			res[j] = max(res[j], res[j - knowledge[paper[i]]] + reward[i]);
		}
	}
	cout << res[T];
	return 0;
} 
