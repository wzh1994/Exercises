#include <iostream>
using namespace std;
#define MAX(_a,_b) ((_a)>(_b))?(_a):(_b)
int main(){
	int n;
	int num[101][101];
	int i, j;
	cin >> n;
	for (i = 0; i < n; i++){
		for (j = 0; j <= i; j++)
			cin >> num[i][j];
	}
	for (i = n - 2; i >= 0; i--){
		for (j = 0; j <= i; j++){
			num[i][j] += MAX(num[i + 1][j], num[i + 1][j + 1]);
		}
	}
	cout << num[0][0];
}