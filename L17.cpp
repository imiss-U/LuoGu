/**
 * @file L17.cpp
 * @author zhangtengfei (20226472@stu.neu.edu.cn)
 * @brief 给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。
 * 给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
 * @version 0.1
 * @date 2024-03-12
 *
 *
 */
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
