#include <iostream>
#include <vector>
#include <string>
using namespace std; 
bool Is(string &str, int start, int end){
	for (int i = start, j = end; i <= j; i++, j--){
		if (str[i] != str[j])
			return false;
	}
	return true;
}
class Solution{
	public:
		vector<vector<string>> res;
		vector<string> path;
		void dfs(string &s, int position){
			if (position >= s.size()){
				res.push_back(path);
				return;
			}
			for (int i = position; i < s.size(); i++){
				if (Is(s, position, i))
					path.push_back(s.substr(position, i - position + 1));
				else
					continue;
				dfs(s, i + 1);
				path.pop_back();
			}
		}
		vector<vector<string>> partition(string s){
			dfs(s, 0);
			return res;
		}
};
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	string str;
	cin >> str;
	Solution sol;
	sol.partition(str);
	for (auto &x : sol.res){
		for (auto &y : x){
			cout << y << " ";
		}
		cout << "\n";
	}
	return 0;
}
