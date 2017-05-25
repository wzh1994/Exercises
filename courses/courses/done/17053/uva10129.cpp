#include <iostream>
#include <string>
#include <cstring>
#include <map>
typedef struct node{
	int in;
	int out;
	node(){}
	node(int i, int o) :in(i), out(o){}
}Degree;
int compare(Degree d){
	if (d.in == d.out) return 1;
	else if (d.in == d.out - 1) return 2;
	else if (d.in == d.out + 1) return 3;
	return 0;
}
#define res(_i,_s,_n) for (int _i=_s;_i<_n;_i++)
using namespace std;
char G[30][30];
char visit[30];
void dfs(int c){
	visit[c] = 0;
	for (int i = 0; i < 27; i++){
		if ((G[c][i]||G[i][c])&&visit[i]){
			dfs(i);
		}
	}
};
int main(){
#ifdef LOCAL
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif
	int N;
	cin >> N;
	map<char, Degree> keys;
	while (N--){
		int n;
		keys.clear();
		memset(G, 0, sizeof(G));
		memset(visit, 0, sizeof(visit));
		cin >> n;
		string line;
		getline(cin, line);
		while (n--){
			getline(cin, line);
			char l = line[0];
			char r = line[line.size() - 1];
			G[l - 'a'][r - 'a']=1;
			if (keys.count(r)){
				keys[r].in++;
			}
			else{
				visit[r-'a'] = 1;
				keys[r] = Degree(1,0);
			}
			if (keys.count(l)){
				keys[l].out++;
			}
			else{
				visit[l-'a'] = 1;
				keys[l] = Degree(0, 1);
			}
		}
		int less = 0;
		int gather = 0;
		int err = 0;
		for (map<char, Degree>::iterator it = keys.begin(); it != keys.end(); it++){
			int r = compare(it->second);
			if (r == 0) {
				err = 1;
				break;
			}
			else if (r == 2){
				less++;
				if (less > 1) {
					err = 1;
					break;
				}
			}
			else if (r == 3){
				gather++;
				if (gather > 1) {
					err = 1;
					break;
				}
			}
		}
		char c = keys.begin()->first;
		dfs(c-'a');
		for (int i = 0; i < 30; i++){
			if (visit[i] == 1) err = 1;
		}
		if (err) cout << "The door cannot be opened." << endl;
		else cout << "Ordering is possible." << endl;
	}
}