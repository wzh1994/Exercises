#include<iostream>
using namespace std;
void goup(char *str){
	char temp = str[0];
	str[0] = str[1];
	str[1] = str[5];
	str[5] = str[4];
	str[4] = temp;
}
void goleft(char *str){
	char temp = str[2];
	str[2] = str[1];
	str[1] = str[3];
	str[3] = str[4];
	str[4] = temp;
}
void copyTo(char* str, char* cp){
	for (int i = 0; i < 6; i++){
		cp[i] = str[i];
	}
}
int compare(char* str, char* str2){
	int same = 1;
	for (int i = 0; i < 6; i++){
		if (str[i] != str2[i]) same=0;
	}
	return same;
}
int cmp(char* str, char*str2){
	if (compare(str, str2)) return 1;
	goleft(str);
	if (compare(str, str2)) return 1;
	goleft(str);
	if (compare(str, str2)) return 1;
	goleft(str);
	if (compare(str, str2)) return 1;
	return 0;
}
int main(){
	char str[13];
	char first[6];
	int same;
	while (cin >> str){
		do{
			same = 0;
			copyTo(str, first);
			if (cmp(first, str + 6)){
				same = 1;
				break;
			}
			copyTo(str, first);
			goup(first);
			if (cmp(first, str + 6)) {
				same = 1;
				break;
			}
			copyTo(str, first);
			goup(first); goup(first);
			if (cmp(first, str + 6)) {
				same = 1;
				break;
			}
			copyTo(str, first);
			goup(first); goup(first); goup(first);
			if (cmp(first, str + 6)) {
				same = 1;
				break;
			}
			copyTo(str, first);
			goleft(first); goup(first);
			if (cmp(first, str + 6)){
				same = 1;
				break;
			}
			copyTo(str, first);
			goleft(first); goleft(first); goleft(first); goup(first);
			if (cmp(first, str + 6)) same = 1;
		} while (0);
		if (same) cout << "TRUE" << endl;
		else cout << "FALSE" << endl;
	}
}