#include <iostream>
#include <cstdio>
#include <iomanip>
#include <cstring>
#include <map>
using namespace std;
int d, s, b;
int rem;
char disks[7][7000];
int cas;
int deal(){
	int n = s*b;
	for (int i = 0; i < n; i++){
		int x = 0;
		int xpos = 0;
		int one = 0;
		for (int j = 0; j < d; j++){
			if (disks[j][i] == 'x'){
				xpos = j;
				x++;
			}
			else if (disks[j][i] == '1'){
				one++;
			}
		}
		if (x>1) return 0;
		else if (x == 1){
			disks[xpos][i] = '0'+(one + rem) % 2;
		}
		else{
			if ((one % 2) != rem) return 0;
		}
	}
	return 1;
}
void print(int num){
	printf("Disk set %d is ", cas);
	if (!num){
		printf("invalid.\n");
		return;
	}
	printf("valid, contents are: ");
	int num_4=0;
	int m = 0;
	for (int i = 0; i < b; i++){
		for (int j = 0; j < d; j++){
			if (i%d == j) continue;
			for (int k = 0; k < s; k++){
				char c = disks[j][i*s + k];
				num_4 *= 2;
				num_4 += c - '0';
				m++;
				if (m == 4) {
					cout << setiosflags(ios::uppercase)<< hex << num_4;
					num_4 = 0;
					m = 0;
				}
			}
		}
	}
	if (m > 0){
		for (; m < 4; m++){
			num_4 *= 2;
		}
		cout << setiosflags(ios::uppercase)<< hex << num_4;
	}
	cout << endl;
}
int main(){
#ifdef LOCAL
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif
	char type;
	cas = 0;
	while (cin >> d >> s >> b >> type){
		memset(disks, 0, sizeof(disks));
		gets(disks[0]);
		rem = type == 'E' ? 0 : 1;
		++cas;
		for (int i = 0; i < d; i++){
			gets(disks[i]);
		}
		print(deal());
	}
}