#include <iostream>
#include <stack>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    stack<char> ustack;
    char tmp;
    int flag = 0;
    while (cin >> tmp) {
        ustack.push(tmp);
        if (ustack.top() == '(')
            flag++;
        if (ustack.top() == ')' && flag != 0) {
            ustack.pop();
            ustack.pop();
            flag--; 
        }
    }
    int m = 0, n = 0;
    while (!ustack.empty()) {
        if (ustack.top() == ')')    
            m++;
        else
            n++;
        ustack.pop();
    }
    if (m % 2 == 0)
        cout << (m + n) / 2;
    else
        cout << (m + n) / 2 + 1;
    return 0;
}