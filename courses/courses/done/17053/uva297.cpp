#include <iostream>
#include <cstring>
#define res(_i,_s,_n) for (int _i=_s;_i<_n;_i++)
using namespace std;
int image[32][32];
int cnt;
void draw(int t, int b, int l, int r);
int main(){
#ifdef LOCAL
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif
	int N;
	cin >> N;
	while (N--){
		memset(image, 0, sizeof(image));
		cnt = 0;
		draw(0, 31, 0, 31);
		draw(0, 31, 0, 31);
		cout << "There are "<<cnt<<" black pixels." << endl;
	}
}
void draw(int t, int b, int l, int r){
	char ch;
	cin >> ch;
	if (ch == 'p'){
		char rowm = (t + b) / 2;
		char colm = (l + r) / 2;
		draw(t, rowm, colm + 1, r);
		draw(t, rowm, l, colm);
		draw(rowm + 1, b, l, colm);
		draw(rowm + 1, b, colm + 1, r);
	}
	else if (ch == 'f'){
		for (int i = t; i <= b; i++){
			for (int j = l; j <= r; j++){
				if (image[i][j] == 0) {
					image[i][j] = 1;
					cnt++;
				}
			}
		}
	}
}