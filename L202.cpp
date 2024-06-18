#include <iostream>
#include <unordered_set>
class Solution {
public:
    bool isHappy(int n) {
        std::unordered_set<int> S;
        while (n) {
            int sum = 0;
            while (n) {
                sum += (n % 10) * (n % 10);
                n /= 10;
            }
            if (sum == 1)
                return true;
            if (S.find(sum) != S.end())
                return false;
            else {
                S.insert(sum);
                n = sum;
            }
        }
        return false; // Add a return statement here
    }
};
int main() {
    int n = 19;
    Solution S;
    std::cout << S.isHappy(n) << std::endl;
    return 0;
}