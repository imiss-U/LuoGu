#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int p1, p2, p3;
    string str;
    cin >> p1 >> p2 >> p3;
    cin >> str;
    string result = "";
    for (int i = 0; str[i]; i++) {
        if (str[i] == '-' && i != 0) {
            char ch1 = str[i - 1], ch2 = str[i + 1];
            if (ch2 == str[i]) {
                while (ch2 == str[i]) {
                    result = result + str[i];
                    i++;
                }
                result = result + str[i];
            }
            else if (ch1 >= ch2 || (48 <= ch1 && ch1 <= 57 && ch2 >= 65)) {
                result = result + str[i];
            }
            else if (ch1 + 1 == ch2) {
                continue;
            }
            else {
                string temp = "";
                char start = ch1 + 1, finally = ch2 - 1;
                if (p1 == 1) {
                    if (ch1 >= 65 && ch1 <= 90) {
                        start = start + 32;
                    }
                    if (ch2 >= 65 && ch2 <= 90) {
                        finally = finally + 32;
                    }
                    for (; start <= finally; start++) {
                        int tmp = p2;
                        while (tmp--) {
                            temp = temp + start;
                        }
                    }
                    if (p3 == 2) {
                        reverse(temp.begin(), temp.end());
                    }
                }
                else if (p1 == 2) {
                    if (ch1 >= 97 && ch1 <= 122) {
                        start = start - 32;
                    }
                    if (ch2 >= 97 && ch2 <= 122) {
                        finally = finally - 32;
                    }
                    for (; start <= finally; start++) {
                        int tmp = p2;
                        while (tmp--) {
                            temp = temp + start;
                        }
                    }
                    if (p3 == 2) {
                        reverse(temp.begin(), temp.end());
                    }
                }
                else {
                    for (; start <= finally; start++) {
                        int tmp = p2;
                        while (tmp--) {
                            temp = temp + '*';
                        }
                    }
                }
                result = result + temp;
            }
        }
        else {
            while (str[i] == '-') {
                result = result + str[i];
                i++;
            }
            result = result + str[i];
        }
    }
    cout << result;
    return 0;
}