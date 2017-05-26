#include <iostream>
#include <cstring>
#include <cstdio>
#define res(_i,_s,_n) for (int _i=_s;_i<_n;_i++)
using namespace std;
char tree[210][210];
void dfs(int i, int j);
int n;
int main(){
#ifdef LOCAL
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif
	int N;
	cin >> N;
	gets(tree[209]);
	while (N--){
		n = 0;
		while ((gets(tree[n])) && tree[n][0] != '#') n++;
		printf("(");
		if (n > 0){
			for (int i = 0; tree[0][i] != '\0'; i++){
				if (tree[0][i] != ' '){
					dfs(0, i);
					break;
				}
			}
		}
		printf(")\n");
	}
}
void dfs(int i, int j){
	printf("%c(",tree[i][j]);
	if (i < n - 1&&tree[i+1][j]=='|'){
		i += 2;
		while (tree[i][j] == '-') j--;
		int l = strlen(tree[i + 1]);
		for (j++; tree[i][j] == '-'&&j<l; j++){
			if (tree[i + 1][j] != ' ') dfs(i + 1, j);
		}
	}
	printf(")");
}