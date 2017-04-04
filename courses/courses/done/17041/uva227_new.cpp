#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main(){
	int n = 0;
	char a[5][10];
	int pos_x, pos_y;
	while (++n){
		memset(a, 0, sizeof(a));
		gets(a[0]);
		if (a[0][0] == 'Z') break;
		for (int i = 1; i < 5; i++)
			gets(a[i]);
		for (int x = 0; x < 5; x++){
			for (int y = 0; y < 5; y++){
				if (a[x][y] == ' '){
					pos_x = x;
					pos_y = y;
				}
				else if (a[x][y] == '\0'){
					pos_x = x;
					pos_y = y;
					a[x][y] = ' ';
				}
			}
		}
		int goon = 1;
		int error = 0;
		while (1){
			char temp[10000];
			int len;
			gets(temp);
			len = strlen(temp);
			for (int i = 0; i < len; i++){
				switch (temp[i]){
				case 'A':
					if (!error){
						if (pos_x < 1) error = 1;
						else {
							a[pos_x][pos_y] = a[pos_x - 1][pos_y];
							pos_x -= 1;
							a[pos_x][pos_y] = ' ';
						}
					}
					break;
				case 'B':
					if (!error){
						if (pos_x > 3) error = 1;
						else {
							a[pos_x][pos_y] = a[pos_x + 1][pos_y];
							pos_x += 1;
							a[pos_x][pos_y] = ' ';
						}
					}
					break;
				case 'L':
					if (!error){
						if (pos_y < 1) error = 1;
						else {
							a[pos_x][pos_y] = a[pos_x][pos_y - 1];
							pos_y -= 1;
							a[pos_x][pos_y] = ' ';
						}
					}
					break;
				case 'R':
					if (!error){
						if (pos_y > 3) error = 1;
						else {
							a[pos_x][pos_y] = a[pos_x][pos_y + 1];
							pos_y += 1;
							a[pos_x][pos_y] = ' ';
						}
					}
					break;
				case '0':
					goon = 0;
					break;
				}
				if (!goon) break;
			}
			if (!goon) break;
		}
		if (n > 1) cout << endl;
		cout << "Puzzle #" << n << ":" << endl;
		if (error) cout << "This puzzle has no final configuration."<<endl;
		else {
			for (int x = 0; x < 5; x++){
				for (int y = 0; y < 4; y++){
					cout << a[x][y] << " ";
				}
				cout << a[x][4] << endl;
			}
		}
	}
	return 0;
}