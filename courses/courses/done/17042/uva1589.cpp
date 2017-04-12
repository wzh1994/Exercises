#include <iostream>
#include <cstring>
using namespace std;
#define H 1//马
#define G 2//将
#define C 3//炮
#define R 4//车
int qipan[11][10];
int isDeliveredACheck(int x,int y){
	int eat = qipan[x][y];
	int ifCheck = 0;
	do{
		//检查将是否碰面
		int gx = 0;
		for (int i = 8; i < 11; i++){
			if (qipan[i][y] == G){
				gx = i;
				ifCheck = 1;
				break;
			}
		}
		if (gx){
			for (int i = x + 1; i < gx; i++){
				if (qipan[i][y]>0) {
					ifCheck = 0;
					break;
				}
			}
		}
		if (ifCheck) break;
		//检查是否有车在将军
		for (int i = x - 1; i > 0; i--){
			if (qipan[i][y] > 0){
				if (qipan[i][y] == R) ifCheck = 1;
				break;
			}
		}
		if (ifCheck) break;
		for (int i = x + 1; i < 11; i++){
			if (qipan[i][y] > 0){
				if (qipan[i][y] == R) ifCheck = 1;
				break;
			}
		}
		if (ifCheck) break;
		for (int i = y - 1; i > 0; i--){
			if (qipan[x][i] > 0){
				if (qipan[x][i] == R) ifCheck = 1;
				break;
			}
		}
		if (ifCheck) break;
		for (int i = y + 1; i < 10; i++){
			if (qipan[x][i] > 0){
				if (qipan[x][i] == R) ifCheck = 1;
				break;
			}
		}
		if (ifCheck) break;
		//检查是否有炮在将军
		int mid = 0;
		for (int i = x + 1; i < 11; i++){
			if (qipan[i][y] > 0){
				mid++;
				if (mid > 1){
					if (qipan[i][y]==C) ifCheck = 1;
					break;
				}
			}
		}
		if (ifCheck) break;
		mid = 0;
		for (int i = y - 1; i > 0; i--){
			if (qipan[x][i] > 0){
				mid++;
				if (mid > 1){
					if (qipan[x][i] == C) ifCheck = 1;
					break;
				}
			}
		}
		if (ifCheck) break;
		mid = 0;
		for (int i = y + 1; i < 10; i++){
			if (qipan[x][i] > 0){
				mid++;
				if (mid > 1){
					if (qipan[x][i] == C) ifCheck = 1;
					break;
				}
			}
		}
		if (ifCheck) break;
		//检查马 x=1 4处 x=2 6处 x=3 8处
		switch (x){
		case 3:
			if (qipan[1][y + 1] == H&&qipan[2][y + 1] == 0) {
				ifCheck = 1;
				break;
			}
			if (qipan[1][y - 1] == H&&qipan[2][y - 1] == 0) {
				ifCheck = 1;
				break;
			}
		case 2:
			if (qipan[x-1][y + 2] == H&&qipan[x-1][y + 1] == 0) {
				ifCheck = 1;
				break;
			}
			if (qipan[x-1][y - 2] == H&&qipan[x-1][y - 1] == 0) {
				ifCheck = 1;
				break;
			}
		case 1:
			if (qipan[x + 1][y + 2] == H&&qipan[x + 1][y + 1] == 0) {
				ifCheck = 1;
				break;
			}
			if (qipan[x + 1][y - 2] == H&&qipan[x + 1][y - 1] == 0) {
				ifCheck = 1;
				break;
			}
			if (qipan[x+2][y + 1] == H&&qipan[x+1][y + 1] == 0) {
				ifCheck = 1;
				break;
			}
			if (qipan[x+2][y - 1] == H&&qipan[x+1][y - 1] == 0) {
				ifCheck = 1;
				break;
			}
		}
	} while (0);
	qipan[x][y] = eat;
	return ifCheck;
}

int main(){
	int num, posX, posY;
	while (cin >> num >> posX >> posY&&num != 0){
		memset(qipan, 0, sizeof(qipan));
		char c;
		int x, y;
		while (num--){
			cin >> c >> x >> y;
			switch (c)
			{
			case 'H':qipan[x][y] = H; break;
			case 'G':qipan[x][y] = G; break;
			case 'C':qipan[x][y] = C; break;
			case 'R':qipan[x][y] = R; break;
			}
		}
		int gx = 0;
		int ifCheck = 0;
		for (int i = 8; i < 11; i++){
			if (qipan[i][posY] == G){
				gx = i;
				ifCheck = 1;
				break;
			}
		}
		if (gx){
			for (int i = posX + 1; i < gx; i++){
				if (qipan[i][posY]>0) {
					ifCheck = 0;
					break;
				}
			}
		}
		if ((!ifCheck)&&(posX<2 || isDeliveredACheck(posX - 1, posY)) && (posX>2 || isDeliveredACheck(posX + 1, posY)) && (posY<5 || isDeliveredACheck(posX, posY - 1)) && (posY>5 || isDeliveredACheck(posX, posY + 1))){
			cout << "YES" << endl;
		}
		else{
			cout << "NO" << endl;
		}
	}
}
