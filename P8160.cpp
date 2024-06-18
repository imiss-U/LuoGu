// ! unfinshed code!!
#include <iostream>
#include <vector>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int N;
	cin >> N;
	vector<int> num;
	int temp;
	int base = 1;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		if (temp % 2 != 0)
			num.push_back(temp);
		else {
			while(temp % 2 == 0) {
				temp /= 2;
				base *= 2;
			}
			for (int j = 1;j <= base; j++)
				num.push_back(temp);
			base = 1;
		}
	}
	int Q, que;
	cin >> Q;
	for (int i = 0; i < Q; i++) {
		cin >> que;	
		cout << num[que - 1] << "\n";
	}
	return 0;
}
