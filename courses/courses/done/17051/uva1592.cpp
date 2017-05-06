#include <iostream>
#include <cstdio>
#include <map>
#include <set>
#include <string>
using namespace std;
#define Debug 0
int main(){
#ifdef LOCAL
	freopen("data.in", "r", stdin);
#endif
	int n, m;
	int database[10050][12];
	while (cin >> m >> n){
		char str[85];
		map<string, int> str_nos;
		int number = 0;
		gets(str);
		for (int i = 0; i < m; i++){
			gets(str);
			int j = 0;
			char *start = str;
			for ( char *loop = str; *loop != '\0'; loop++){
				if (*loop == ','){
					*loop = '\0';
					string s(start);
					start = loop + 1;
					if (str_nos.count(s)){
						database[i][j++] = str_nos[s];
					}
					else {
						database[i][j++] = number;
						str_nos[s] = number++;
					}
				}
			}
			string s(start);
			if (str_nos.count(s)){
				database[i][j] = str_nos[s];
			}
			else {
				database[i][j] = number;
				str_nos[s] = number++;
			}
		}
#if Debug
		for (int i = 0; i < m; i++){
			for (int j = 0; j < n; j++){
				cout << database[i][j] << " ";
			}
			cout << endl;
		}
#endif
		int no = 0;
		for (int i = 0; i < n-1; i++){
			if (no) break;
			for (int j = 0; j < m - 1; j++){
				if (no) break;
				for (int k = j + 1; k < m; k++){
					if (no) break;
					if (database[j][i] == database[k][i]){
						for (int l = i + 1; l < n; l++){
							if (database[j][l] == database[k][l]){
								cout << "NO" << endl;
								cout << j + 1 << " " << k + 1 << endl;
								cout << i + 1 << " " << l + 1 << endl;
								no = 1;
								break;
							}
						}
					}
				}
			}
		}
		if (!no) cout << "YES" << endl;
	}
}