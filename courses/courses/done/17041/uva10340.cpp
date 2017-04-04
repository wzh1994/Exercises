#include <cstdio>
#define LEN 100010
int isSub(char* str1,char *str2){
	int i;
	int j;
	for (i = j = 0; str2[i] != '\0'; i++){
		if (str2[i] == str1[j]) j++;
		if (str1[j] == '\0') return 1;
	}
	return 0;
}
int main(){
	char str1[LEN];
	char str2[LEN];
	char yes[4] = { "Yes" };
	char no[3] = { "No" };
	while (~scanf("%s%s", &str1, &str2)){
		printf("%s\n", isSub(str1,str2)?yes:no);
	}
}