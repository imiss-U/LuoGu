#include <iostream>
#include <stack>
#include <vector>
using namespace std;
// string f(string& str, string target) {

// }
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int n, m;
    cin >> n >> m;
    cin.ignore();
    string str;
    stack<string> s;

    string factor;
    getline(cin, str);
    bool flag = false;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == ' ') {
            if (factor != "") {
                if (flag) {
                    factor += ")";
                    flag = false;
                }
                s.push(factor);
                factor = "";
            }
        }
        else if (str[i] == '+') {
            string op1 = s.top();
            s.pop();
            string op2 = s.top();
            s.pop();
            s.push("(" + op2 + "+" + op1 + ")");
            factor = "";
        }
        else if (str[i] == '-') {
            if (str[i + 1] == ' ' || i == str.size() - 1) {
                string op1 = s.top();
                s.pop();
                string op2 = s.top();
                s.pop();
                s.push("(" + op2 + "-" + op1 + ")");
                factor = "";
            }
            else {
                factor = factor + "(" + str[i];
                flag = true;
            }
        }
        else if (str[i] == '*') {
            string op1 = s.top();
            s.pop();
            string op2 = s.top();
            s.pop();
            s.push(op2 + "*" + op1);
            factor = "";
        }
        else {
            factor += str[i];
        }
    }
    string ori = "";
    while (!s.empty()) {
        ori += s.top();
        s.pop();
        if (!s.empty()) ori += "+";
    }
    for (int i = 0; i < m; i++) {
        vector<string> v(n);
        string res = ori, temp = ori;
        int target;
        cin >> target;
        for (int j = 0; j < n; j++) {
            cin >> v[j];
            if (v[j][0] == '-') {
                v[j] = "(" + v[j] + ")";
            }
            for (int k = 0; k < ori.size(); k++) {
                if (ori[k] == 'x' && ori[k + 1] == j + '0' && ori[k + 1] != target + '0') {
                    res = ori.replace(k, 2, v[j]);
                }
            }
            ori = temp;
        }
        cout << res << endl;
    }
    return 0;
}