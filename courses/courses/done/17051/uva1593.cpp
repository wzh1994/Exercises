#include <iostream>
#include <string>
#include <cstdio>
#include <queue>
#include <sstream>
#include <cstring>
using namespace std;
int main(){
#ifdef LOCAL
	freopen("data.in", "r", stdin);
#endif
	string line;
	int max[180];
	memset(max, 0, sizeof(max));
	queue<queue<string>> lines;
	while (getline(cin, line)){
		istringstream s(line);
		string word;
		queue<string> row;
		int i = 0;
		while (s >> word){
			if (word.length() > max[i]) max[i] = word.length();
			i++;
			row.push(word);
		}
		lines.push(row);
	}
	while (!lines.empty()){
		queue<string> row = lines.front();
		lines.pop();
		int i = 0;
		while (!row.empty()){
			string word = row.front();
			row.pop();
			cout << word;
			if (row.empty()) break;
			int n = max[i++] - word.length()+1;
			for (int j = 0; j < n; j++)
				cout << " ";
		}
		cout << endl;
	}
}