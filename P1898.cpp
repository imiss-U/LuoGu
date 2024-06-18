#include <iostream>
#include <map>
#include <string>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	string str;
	cin >> str;
	int ST;
	cin >> ST;
	map<char, int> myMap;
	char temp = 'A';
	for (int i = ST; i < 26 + ST; i++) {
		myMap.insert({temp, i});
		temp++;
	}
	string tmp;
	for (int i = 0; i < str.length(); i++) {
		tmp = tmp + to_string(myMap.at(str[i]));
	}
	string Old = tmp, New;
	do {
		for (int i = 0, j = 1; j < Old.length(); i++, j++) {
			New = New + char((Old[i] - '0' + Old[j] - '0') % 10 + 48);
		}
		Old = New;
		New.clear();
	}
	while (Old.length() > 2 && Old != "100");
	if (Old[0] == '0')
		Old = Old.substr(1);
	cout << Old;
	return 0;
}
