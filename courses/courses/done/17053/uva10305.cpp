#include <iostream>
#include <cstring>
#define res(_i,_s,_n) for (int _i=_s;_i<_n;_i++)
using namespace std;
int tasks[105][105];
int done[105];
int order[105];
int n, m,k;
void dfs(int index);
int main(){
#ifdef LOCAL
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif
	while ((cin >> n >> m) && (m||n)){
		int i, j;
		k = n-1;
		memset(tasks, 0, sizeof(tasks));
		memset(done, 0, sizeof(done));
		memset(order, 0, sizeof(order));
		while (m--){
			cin >> i >> j;
			tasks[i][j] = 1;
		}
		for (int i = 1; i <= n; i++){
			if (done[i] == 0) {
				dfs(i);
			}
		}
		cout << order[0];
		for (int i = 1; i < n;i++)
			cout <<" "<< order[i];
		cout << endl;
	}
}
void dfs(int index){
	done[index] = -1;
	for (int i = 1; i <= n; i++){
		if (tasks[index][i]>0){
			if (done[i] == 0) dfs(i);
		}
	}
	order[k--] = index;
	done[index] = 1;
}