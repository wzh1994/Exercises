#include <cstdio>
#include <cstring>
#define MAX 205;
int check(char* str1, char* str2){
	int j;
	for (j = 0; str1[j] != '\0'&&str2[j] != '\0'; j++){
		if (str1[j]-'0' + str2[j]-'0' > 3) return 0;
	}
	if (str1[j] == '\0'){
		while (str2[j] != '\0') j++;
	}
	else if (str2[j] == '\0'){
		while (str1[j] != '\0') j++;
	}
	return j;
}
int main(){
	char str1[105];
	char str2[105];
	int length1;
	int length2;
	while (~scanf("%s %s", &str1, &str2)){
		int success = 0;
		for (int i = 0; str1[i] != '\0'; i++){
			int result = check(&str1[i], str2);
			if (result) {
				length1=i + result;
				success = 1;
				break;
			}
		}
		if (!success) length1=strlen(str1) + strlen(str2);
		success = 0;
		for (int i = 0; str2[i] != '\0'; i++){
			int result = check(&str2[i], str1);
			if (result) {
				length2 = i + result;
				success = 1;
				break;
			}
		}
		if (!success) length2 = strlen(str1) + strlen(str2);
		printf("%d\n", length1 < length2 ? length1 : length2);
	}
	return 0;
}