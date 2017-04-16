#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;
typedef struct node{
	struct node *left;
	struct node *right;
	struct node *top;
	struct node *below;
}*DotNode,Node;
int isSquare(DotNode dot,int k){
	int i;
	for (i = 0; i < k; i++){
		if (dot->below) dot = dot->below;
		else return 0;
	}
	for (i = 0; i < k; i++){
		if (dot->right) dot = dot->right;
		else return 0;
	}
	for (i = 0; i < k; i++){
		if (dot->top) dot = dot->top;
		else return 0;
	}
	for (i = 0; i < k; i++){
		if (dot->left) dot = dot->left;
		else return 0;
	}
	return 1;
}
int main(){
	int n, m;
	DotNode dot[10][10];
	int num[10];
	int proNum=0;
	while (cin >> n >> m){
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= n; j++){
				dot[i][j] = (DotNode)malloc(sizeof(Node));
				dot[i][j]->below = NULL;
				dot[i][j]->top = NULL;
				dot[i][j]->left = NULL;
				dot[i][j]->right = NULL;
			}
		}
		memset(num, 0, sizeof(num));
		char op;
		int i, j;
		while (m--){
			cin >> op >> i >> j;
			switch (op){
			case 'H':
				dot[i][j]->right = dot[i][j + 1];
				dot[i][j + 1]->left = dot[i][j];
				break;
			case 'V':
				dot[j][i]->below = dot[j + 1][i];
				dot[j + 1][i]->top = dot[j][i];
				break;
			}
		}
		for (i = 1; i < n; i++){
			for (j = 1; j < n; j++){
				int bound = n - i < n - j ? n - i : n - j;
				for (int k = 1; k <= bound; k++){
					if (isSquare(dot[i][j], k)){
						num[k]++;
					}
				}
			}
		}
		if (++proNum>1){
			cout << endl << "**********************************" << endl<<endl;
		}
		cout << "Problem #" << proNum << endl<<endl;
		int sym = 1;
		for (i = 1; i < n; i++){
			if (num[i]>0){
				sym = 0;
				cout << num[i] << " square (s) of size " << i << endl;
			}
		}
		if (sym) cout << "No completed squares can be found." << endl;
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= n; j++){
				free(dot[i][j]);
			}
		}
	}
	return 0;
}
