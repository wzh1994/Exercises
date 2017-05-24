#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <vector>
#include <algorithm>
#define res(_i,_s,_n) for (int _i=_s;_i<_n;_i++)
using namespace std;
const char letter[16][5] = { "0000", "0001", "0010", "0011", "0100", "0101", "0110", "0111", "1000", "1001", "1010", "1011", "1100", "1101", "1110", "1111" };
int m, n;
char grid[200][205];
int label[200][205];
int leftBorder[201];
int rightBorder[201];
int topBorder[201];
int bottomBorder[201];
void initBorder();
void findContours(int i, int j, int lb);
void initContours(int i, int j, int lb);
void findHole(int i, int j, int lb);
int isInContours(int i, int j);
vector<char> chars;
int main(){
#ifdef LOCAL
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif
	int cas = 0;
	while ((cin >> m >> n) && m && n){
		char temp[51];
		memset(label, 0, sizeof(label));
		res(i, 0, m){
			scanf("%s", &temp);
			res(j, 0, n){
				int c = isdigit(temp[j]) ? temp[j] - '0' : tolower(temp[j]) - 'a' + 10;
				strncpy(grid[i] + 4 * j, letter[c], 4);
			}
			grid[i][4 * n] = '\0';
		}
		n *= 4;
		int cnt = 0;
		cout << "Case "<<++cas<<": ";
		chars.clear();
		res(i, 0, m){
			if (grid[i][0] == '0'&&label[i][0]==0) initContours(i, 0, 1);
			if (grid[i][n - 1] == '0'&&label[i][n-1] == 0) initContours(i, n - 1, 1);
		}
		res(i, 0, n){
			if (grid[0][i] == '0'&&label[0][i] == 0) initContours(0, i, 1);
			if (grid[m - 1][i] == '0'&&label[m-1][i] == 0) initContours(m - 1, i, 1);
		}
		res(i, 0, m){
			res(j, 0, n){
				if (grid[i][j] == '1'&&label[i][j] == 0){
					initBorder();
					findContours(i, j, ++cnt);
					int hole = 0;
					res(r, topBorder[200], bottomBorder[200]){
						res(c, leftBorder[200], rightBorder[200]){
							if (grid[r][c] == '0'&&label[r][c] == 0 && isInContours(r, c)){
								findHole(r, c, ++hole);
							}
						}
					}
					chars.push_back((hole == 0 ? 'W' : hole == 1 ? 'A' : hole == 2 ? 'K' : hole == 3 ? 'J' : hole == 4 ? 'S' :'D'));
				}
			}
		}
		sort(chars.begin(), chars.end());
		res(i, 0, chars.size()){
			cout << chars[i];
		}
		cout << endl;
	}
}
void findContours(int i, int j, int lb){
	if (i < 0 || i >= m || j < 0 || j >= n) return;
	if (grid[i][j] == '1'&&label[i][j] == 0) {
		label[i][j] = lb;
		if (j < leftBorder[i]){
			leftBorder[i] = j;
			if (j < leftBorder[200]) 
				leftBorder[200] = j;
		}
		if (j > rightBorder[i]){
			rightBorder[i] = j;
			if (j > rightBorder[200])
				rightBorder[200] = j;
		}
		if (i < topBorder[j]){
			topBorder[j] = i;
			if (i < topBorder[200])
				topBorder[200] = i;
		}
		if (i > bottomBorder[j]){
			bottomBorder[j] = i;
			if (i > bottomBorder[200])
				bottomBorder[200] = i;
		}
		findContours(i - 1, j, lb);
		findContours(i + 1, j, lb);
		findContours(i, j - 1, lb);
		findContours(i, j + 1, lb);
	}
}
void initBorder(){
	res(i, 0, 201){
		leftBorder[i] = 200;
		rightBorder[i] = -1;
		topBorder[i] = 200;
		bottomBorder[i] = -1;
	}
}
int isInContours(int i,int j){
	if (j <= leftBorder[i] || j >= rightBorder[i] || i <= topBorder[j] || i >= bottomBorder[j]) return 0;
	return 1;
}
void findHole(int i, int j, int lb){
	if (!isInContours(i, j)) return;
	if (grid[i][j] == '0'&&label[i][j] == 0){
		label[i][j] = lb;
		res(dr, -1, 2){
			res(dc, -1, 2){
				findHole(i + dr, j + dc, lb);
			}
		}
	}
}
void initContours(int i, int j, int lb){
	if (i < 0 || i >= m || j < 0 || j >= n) return;
	if (grid[i][j] == '0'&&label[i][j] == 0){
		label[i][j] = lb;
		res(dr, -1, 2){
			res(dc, -1, 2){
				initContours(i + dr, j + dc, lb);
			}
		}
	}
}