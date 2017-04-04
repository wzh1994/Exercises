#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define PRINT 1;
int main(){
	int r, c;
	char puzzle[10][11];
	char puzzle_num[10][11];
	int cycle = 0;
	int number;
	while ((scanf("%d",&r))&&r!=0){
		scanf("%d", &c);
		memset(puzzle, 0, sizeof(puzzle));
		memset(puzzle_num, 0, sizeof(puzzle_num));
		number = 0;
		for (int i = 0; i < r; i++)
			scanf("%s", &puzzle[i]);
		if (cycle++) cout << endl;
		cout << "puzzle #" << cycle << ":" << endl;
		for (int i = 0; i < r; i++){
			for (int j = 0; j < c; j++){
				if (puzzle[i][j]!='*'&&(i == 0 || j == 0 || puzzle[i - 1][j] == '*' || puzzle[i][j - 1] == '*'))
					puzzle_num[i][j] = ++number;
			}
		}
		cout << "Across" << endl;
		for (int i = 0; i < r; i++){
			for (int j = 0; j < c; j++){
				if (puzzle[i][j] == '*'){
					if (j>0&& puzzle[i][j - 1] != '*')
						cout << endl;
				}
				else if (j == 0 || puzzle[i][j - 1] == '*')
					printf("%3d.%c", puzzle_num[i][j], puzzle[i][j]);
				else{
					printf("%c", puzzle[i][j]);
				}
			}
			if (puzzle[i][c - 1] != '*') printf("\n");
		}
		cout << "Down" << endl;
		for (int i = 0; i < r; i++){
			for (int j = 0; j < c; j++){
				if ((i == 0 || puzzle[i - 1][j] == '*') && puzzle[i][j] != '*'){
					printf("%3d.%c", puzzle_num[i][j], puzzle[i][j]);
					int k = i + 1;
					while (k < r&&puzzle[k][j] != '*'){
						printf("%c", puzzle[k][j]);
						k++;
					}
					printf("\n");
				}
			}
		}
	}
}