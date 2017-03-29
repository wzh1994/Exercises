#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
int trans(char c);
int numbers[10000000];
int main(){
	
	int totle;
	scanf("%d", &totle);
	getchar();
	memset(numbers, 0, sizeof(numbers));
	for (; totle > 0; totle--){
		char c;
		int temp = 0;
		while ((c = getchar()) != '\n'){
			if (c != '-') {
				temp *= 10;
				temp += trans(c);
			}
		}
		numbers[temp]++;
	}
	int dup = 0;
	for (int i = 0; i<10000000; i++){
		if (numbers[i] > 1) {
			printf("%03d-%04d %d\n", i / 10000, i % 10000, numbers[i]);
			dup = 1;
		}
	}
	if (!dup) printf("No duplicates.\n");
}
int trans(char c){
	if (c >= '0'&&c <= '9') return c - '0';
	if (c >= 'A'&&c <= 'Q') return 2 + (c - 'A') / 3;
	return 2 + (c - 'A' - 1) / 3;
}