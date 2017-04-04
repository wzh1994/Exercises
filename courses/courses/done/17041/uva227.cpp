#include <iostream>
#include <cstring>
using namespace std;
int puzzle(){
	int i = 0;
	int end = 0;
	while (++i){
		char a[6][6];
		int pos_x=0, pos_y=0;
		memset(a, 0, sizeof(a));
		for (int x = 1; x < 6; x++){
			int skip = 0;
			for (int y = 1; y < 6; y++){
				a[x][y]=cin.get();
				if (a[x][y] == 'Z') {
					end = 1;
					break;
				}
				else if (a[x][y] == ' '){
					pos_x = x;
					pos_y = y;
				}
				else if (a[x][y] == '\n'){
					a[x][y] = ' ';
					pos_x = x;
					pos_y = y;
					skip = 1;
				}
			}
			if (end) break;
			char ch;
			if (!skip){
				do{
					ch = cin.get();
				} while (ch != '\n');
			}
		}
		if (end) break;
		char ch;
		int error = 0;
		do{
			ch = cin.get();
			switch (ch){
			case 'A':
				if (pos_x < 2) error = 1;
				else {
					a[pos_x][pos_y] = a[pos_x-1][pos_y];
					pos_x -= 1;
					a[pos_x][pos_y] = ' ';
				}
				break;
			case 'B':
				if (pos_x > 4) error = 1;
				else {
					a[pos_x][pos_y] = a[pos_x+1][pos_y];
					pos_x += 1;
					a[pos_x][pos_y] = ' ';
				}
				break;
			case 'L':
				if (pos_y < 2) error = 1;
				else {
					a[pos_x][pos_y] = a[pos_x ][pos_y-1];
					pos_y -= 1;
					a[pos_x][pos_y] = ' ';
				}
				break;
			case 'R':
				if (pos_y > 4) error = 1;
				else {
					a[pos_x][pos_y] = a[pos_x][pos_y + 1];
					pos_y += 1;
					a[pos_x][pos_y] = ' ';
				}
				break;
			}
			if (error) break;
			/*cout << endl;
			for (int x = 1; x < 6; x++){
				for (int y = 1; y < 6; y++){
					cout << a[x][y];
				}
				cout << endl;
			}
			cout << endl;*/
		} while (ch != '0');
		if (i > 1) cout << endl;
		cout << "Puzzle #" << i << ":" << endl;
		if (error) cout << "This puzzle has no final configuration."<<endl;
		else {
			for (int x = 1; x < 6; x++){
				for (int y = 1; y < 5; y++){
					cout << a[x][y]<<" ";
				}
				cout<<a[x][5] << endl;
			}
		}
		do{
			ch = cin.get();
		} while (ch != '\n');
	}
	return 0;
}