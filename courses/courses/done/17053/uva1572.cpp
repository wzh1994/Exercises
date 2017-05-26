#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
#define res(_i,_s,_n) for (int _i=_s;_i<_n;_i++)
#define getVertex(_c,_s) (_c=='0'?-1:((_c-'A')*2+(_s=='+'?1:0)))
#define getPair(_n) (_n^1)
using namespace std;
int G[55][55];
int visit[55];
set<int> vertex;
int cyc = 0;
void dfs(int n);
void connect(int i,int j){
	if (i == -1 || j == -1) return;
	vertex.insert(i);
	G[getPair(i)][j] = 1;
}
int main(){
#ifdef LOCAL
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif
	int n;
	char line[10];
	while (cin >> n){
		memset(G, 0, sizeof(G));
		memset(visit, 0, sizeof(visit));
		vertex.clear();
		while (n--){
			scanf("%s", &line);
			for (int i = 0; i < 7; i += 2){
				for (int j = 0; j < 7; j += 2){
					if (i == j) continue;
					int v1 = getVertex(line[i], line[i + 1]);
					int v2 = getVertex(line[j], line[j + 1]);
					connect(v1, v2);
				}
			}
		}
		int num = 0;
		cyc = 0;
		for (set<int>::iterator it = vertex.begin(); it != vertex.end(); it++){
			if (cyc) break;
			if (visit[*it] == 0){
				dfs(*it);
			}
		}
		if (cyc) cout << "unbounded" << endl;
		else cout << "bounded" << endl;
	}
}
void dfs(int n){
	if (cyc) return;
	visit[n] = -1;
	for (set<int>::iterator it = vertex.begin(); it != vertex.end(); it++){
		if (G[n][*it] == 1){ 
			if (visit[*it] == -1) {
				cyc = 1;
				return;
			}
			else if (visit[*it] == 0) dfs(*it);
		}
	}
	visit[n] = 1;
}