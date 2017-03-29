#include <iostream>
#include <cstring>
#define MAX(_a,_b) ((_a)>(_b))?(_a):(_b)
int dfs(int i, int j);
int maxLength[100][100];
int height[100][100];
int R, C;
int main(){
	
	std::cin >> R >> C;
	
	memset(maxLength, 0, sizeof(maxLength));
	
	for (int i = 0; i < R; ++i){
		for (int j = 0; j < C; j++)
			std::cin >> height[i][j];
	}
	for (int i = 0; i < R; ++i){
		for (int j = 0; j < C; j++)
			dfs(i, j);
	}
	int max = 1;
	for (int i = 0; i < R; ++i){
		for (int j = 0; j < C; j++){
			max = MAX(max, maxLength[i][j]);
		}
	}
	std::cout << max;

}
int dfs(int i, int j){
	if (maxLength[i][j]>0) return maxLength[i][j];
	int length = 1;
	if (i>0&&height[i][j]>height[i-1][j]){
		length = MAX(length, dfs(i - 1, j) + 1);
	}
	if (j > 0 && height[i][j]>height[i][j-1]){
		length = MAX(length, dfs(i, j-1) + 1);
	}
	if (i<R - 1 && height[i][j]>height[i + 1][j]){
		length = MAX(length, dfs(i + 1, j) + 1);
	}
	if (j<C - 1 && height[i][j]>height[i][j + 1]){
		length = MAX(length, dfs(i, j + 1) + 1);
	}
	maxLength[i][j] = length;
	return length;
}