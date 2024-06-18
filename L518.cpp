#include <iostream>
#include <vector>
using namespace std;
int res[5010];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int V, temp;
	vector<int> coins;
	cin >> V;
	while(cin >> temp)
		coins.push_back(temp);
	res[0] = 1;
	int N = coins.size();
	for (int i = 0; i < N; i++){
		for (int j = coins[i]; j <= V; j++){
			res[j] += res[j - coins[i]];
		}
	}
	cout << res[V];
	return 0;
} 
