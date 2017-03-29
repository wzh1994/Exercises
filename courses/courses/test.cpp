#include <stdio.h>
void read(){
	int a;
	if ((a = getchar()) != '\n'){
		read();
		printf("%c", a);
	}
}
int main(){
	read();
}