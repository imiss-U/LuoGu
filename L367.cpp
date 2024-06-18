#include <iostream>
using namespace std;
class Solution {
public:
    bool isPerfectSquare(int num) {
    	if (num == 1)
    		return true;
		int left = 1, right = num >> 1;
		while(left <= right){
			int mid = left + ((right - left) >> 1);
			if (mid * mid == num)
				return true;
			else if (mid * mid > num)
				right = mid - 1;
			else if (mid * mid < num)
				left = mid + 1;
		}
		return false;
    }
};
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int num;
	cin >> num;
	Solution sol;
	bool flag = sol.isPerfectSquare(num);
	cout << flag;
	return 0;
}
