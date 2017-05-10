#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
#define TOP 0
#define BUT 1
#define LEFT 2
#define RIGHT 3
#define TOPLEFT 4
#define TOPRIGHT 5
#define BUTLEFT 6
#define BUTRIGHT 7
#define changePlayer player=player == 'B' ? 'W' : 'B'
#define changeOthello(_pos) _pos=player == 'B' ? 'B' : 'W';
char othello[10][10];
char player;
int calc(int op, int rr, int cc,int dir = -1){
	int sum = 0;
	int r, c;
	for (int i = 0; i < 8; i++){
		if (((dir >> i) & 1) == 0) continue;
		r = rr;
		c = cc;
		int top = i == TOP || i == TOPLEFT || i == TOPRIGHT;
		int but = i == BUT || i == BUTLEFT || i == BUTRIGHT;
		int left = i == LEFT || i == TOPLEFT || i == BUTLEFT;
		int right = i == RIGHT || i == TOPRIGHT || i == BUTRIGHT;
		if (top&&r<2 || but&&r>5 || left&&c<2 || right&&c>5) continue;
		int count = 0;
		while (1)
		{
			if (top) --r;
			if (but) ++r;
			if (left) --c;
			if (right) ++c;
			if (c<0 || c>7 || r<0 || r>7) break;
			if (othello[r][c] ==(player=='W'?'B':'W')){
				if (op)
					changeOthello(othello[r][c]);
				count++;
			}
			else {
				if (othello[r][c] == player && count)
					sum += (1 << i);
				break;
			}
		}
	}
	return op==0?sum:1;
}
int main(){
#ifdef LOCAL
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif
	int n;
	cin >> n;
	string cmd;
	getline(cin, cmd);
	for (int cyc = 0; cyc < n;cyc++){
		if (cyc) cout << endl;
		memset(othello,0,sizeof(othello));
		for (int i = 0; i < 8; i++){
			gets(othello[i]);
		}
		while (getline(cin, cmd) && cmd != "Q"){
			if (cmd[0] == 'W') player = 'W';
			else if (cmd[0] == 'B') player = 'B';
			else if (cmd[0] == 'M'){
				int r = cmd[1] - '0'-1;
				int c = cmd[2] - '0'-1;
				int dir = calc(0, r, c);
				if (dir > 0){
					calc(1, r, c, dir);
				}
				else{
					changePlayer;
					dir = calc(0, r, c);
					calc(1, r, c, dir);
				}
				changeOthello(othello[r][c]);
				int xx = 0;
				int yy = 0;
				for (int i = 0; i < 8; i++){
					for (int j = 0; j < 8; j++){
						if (othello[i][j] == 'B') xx++;
						else if (othello[i][j] == 'W') yy++;
					}
				}
				printf("Black - %2d White - %2d\n", xx, yy);
				changePlayer;
			}
			else if (cmd[0] == 'L'){
				int num = 0;
				for (int i = 0; i < 8; i++){
					for (int j = 0; j < 8; j++){
						if (othello[i][j] != '-') continue;
						int dir = calc(0, i, j);
						if (dir>0){
							if (num) cout << " ";
							cout << "(" << i+1 << "," << j+1 << ")";
							num++;
						}
					}
				}
				if (!num){
					cout << "No legal move.";
				}
				cout << endl;
			}
		}
		for (int i = 0; i < 8; i++){
			puts(othello[i]);
		}
	}
}