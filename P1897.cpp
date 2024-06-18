#include <iostream>
#include <algorithm>
using namespace std;
int f[100001], s[20000001];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0) ,cout.tie(0);
	int n;
	int sum = 0;
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> f[i];
		s[f[i]]++;	
	}
	auto Max = max_element(f, f + n);
	auto Min = min_element(f, f + n);
	for (int k = *Min; k <= *Max; k++){
		if (s[k])
			sum++;
	}
	cout << (*Max) * 10 + n + sum * 5;
	return 0;
}
