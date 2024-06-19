
#include <iostream>
#include <vector>
#include <string>
using namespace std;
const string letter[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
vector<string> res;
string ch;
void dfs(string& str, int position){
	if (str.size() == position){
		res.push_back(ch);
		return;
	}
	string tmp = letter[str[position] - '0'];
	for (int i = 0; i < tmp.size(); i++){
		ch.push_back(tmp[i]);
		dfs(str, position + 1);
		ch.pop_back();
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	string str;
	cin >> str;
	dfs(str, 0);
	for (auto& x : res){
		cout << x << "\n";
	}
	return 0;
}
