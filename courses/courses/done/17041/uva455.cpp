#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main(){
	int n;
	cin >> n;
	while (n--){
		char str[105];
		scanf("%s",&str);
		int length = strlen(str);
		int symbol;
		for (int i = 1; i < length; i++){
			if (str[i] == str[0]&&length%i==0){
				int j;
				for (j = i + 1; j < length; j++){
					if (str[j] != str[j - i]) break;
				}
				if (j==length){
					cout << i << endl;
					break;
				}
			}
			if (i == length - 1){
				cout << length << endl;
			}
		}
		if (length == 1) cout << length << endl;
		if (n) cout << endl;
	}
}