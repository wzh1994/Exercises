#include <cstdio>
int main(){
	int n;
	scanf("%d", &n);
	getchar();
	while (n-- > 0){
		char ch;
		int total = 0;
		int pre = 0;
		while ((ch = getchar()) != '\n'){
			if (ch == 'O')
				total += ++pre;
			else {
				pre = 0;
			}
		}
		printf("%d\n", total);
	}
}