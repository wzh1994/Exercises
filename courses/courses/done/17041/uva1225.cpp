#include <iostream>
#include <cstring>
using namespace std;
int main(){
	int n;
	cin >> n;
	while (n--){
		int frequence[10];
		int num;
		cin >> num;
		memset(frequence, 0, sizeof(frequence));
		for (int i = 1; i <= num; i++){
			int j = i;
			while (j != 0){
				frequence[j % 10]++;
				j /= 10;
			}
		}
		for (int i = 0; i < 9; i++){
			cout << frequence[i] << " ";
		}
		cout <<frequence[9]<< endl;
	}
}