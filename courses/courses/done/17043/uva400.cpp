#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
#define LineWidth 60
int main(){
#ifdef LOCAL
	freopen("data.in", "r", stdin);
#endif
	int n;
	while (cin >> n){
		cout << "------------------------------------------------------------" << endl;
		string s;
		vector<string> words;
		int maxLen = 0;
		while (n--){
			cin >> s;
			if (s.length() > maxLen) maxLen = s.length();
			words.push_back(s);
		}
		n = words.size();
		int col = 1 + (LineWidth - maxLen) / (maxLen + 2);
		int row = (n+col-1)/col;
		sort(words.begin(), words.end());
		for (int i = 0; i < row; i++){
			for (int j = 0; j < col; j++){
				int pos = j*row + i;
				if (pos >= n) continue;
				if (j>0) cout << "  ";
				cout << words[pos];
				for (int k = words[pos].size(); k < maxLen; k++) cout << " ";
			}
			cout << endl;
		}
	}
}