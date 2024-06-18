#include <iostream>
#include <vector>
using namespace std;
int res[1010];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int V;
	vector<int> nums;
	cin >> V;
	int temp;
	while(cin >> temp){
		nums.push_back(temp);
	}
	res[0] = 1;
	for (int i = 0; i <= V; i++){
		for (int j = 0; j < nums.size(); j++){
			if (i >= nums[j])
				res[i] += res[i - nums[j]];
		}
	}
	cout << res[V];
	return 0;
}
