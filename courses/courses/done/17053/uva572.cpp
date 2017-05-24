#include <iostream>
#include <cstdio>
#include <cstring>
#define res(_i,_s,_n) for (int _i=_s;_i<_n;_i++)
using namespace std;
char grid[100][100];
int label[100][100];
int m, n;
void dfs(int i, int j, int label);
int main(){
#ifdef LOCAL
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif
	while ((cin >> m >> n)&&m&&n){
		memset(label,0, sizeof(label));
		memset(grid, 0, sizeof(grid));
		res(i, 0, m){
			scanf("%s", &grid[i]);
		}
		int cnt = 0;
		res(i, 0, m){
			res(j, 0, n){;
				if (grid[i][j] == '@'&&label[i][j] == 0) 
					dfs(i, j, ++cnt);
			}
		}
		cout << cnt << endl;
	}
}
void dfs(int i, int j, int lab){
	//cout << "i:" << i << " j:" << j << " label:" << lab << endl;
	if (i < 0 || j < 0 || i >= m || j >= n) return;
	if (grid[i][j] == '@'&&label[i][j] == 0){
		label[i][j] = lab;
		dfs(i - 1, j - 1, lab);
		dfs(i - 1, j, lab);
		dfs(i - 1, j + 1, lab);
		dfs(i , j - 1, lab);
		dfs(i , j + 1, lab);
		dfs(i + 1, j - 1, lab);
		dfs(i + 1, j , lab);
		dfs(i + 1, j + 1, lab);
	}
}