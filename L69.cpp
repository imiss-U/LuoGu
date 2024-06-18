#include <iostream>
using namespace std;
class Solution {
public:
    int mySqrt(int x) {
		int left = 1, right = x;
		while(left <= right){
			int mid = left + ((right - left) >> 1);
			if (mid * mid <= x && (mid + 1) * (mid + 1) > x)
				return mid;
			else if (mid * mid > x)
				right = mid - 1;
			else if ((mid + 1) * (mid + 1) <= x)
				left = mid + 1;
		}
    }
};
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int x;
	cin >> x;
	Solution sol;
	int res = sol.mySqrt(x);
	cout << res;
	return 0;
}
