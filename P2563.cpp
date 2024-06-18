#include <iostream>
using namespace std;
const int data[46] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,181,191,193,197,199};
int volum[201];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	volum[0] = 1;
	int temp;
	while(cin >> temp) {
		for (int i = 0; i < 46; i++) {
			for (int j = data[i]; j <= temp; j++) {
				volum[j] += volum[j - data[i]];
			}
		}
		cout << volum[temp] << "\n";
		for (int i = 1; i <= 201; i++)
			volum[i] = 0;
	}
	return 0;
}
