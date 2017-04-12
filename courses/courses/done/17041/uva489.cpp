#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
int main(){
	int rnd;
	while (cin >> rnd&&rnd >= 0){
		string solution;
		string guesses;
		cin >> solution >> guesses;
		char characters[26];
		char guess[26];
		int chance = 7;
		memset(characters, 0, sizeof(characters));
		memset(guess, 0, sizeof(guess));
		int sum = 0;
		printf("Round %d\n",rnd);
		for (string::iterator i = solution.begin(); i < solution.end(); i++){
			if (characters[*i - 'a'] == 0){
				characters[*i - 'a'] = 1;
				sum ++;
			}
		}
		int ok = 0;
		for (string::iterator i = guesses.begin(); i < guesses.end(); i++){
			if (guess[*i - 'a']) continue;
			guess[*i - 'a']++;
			if (characters[*i-'a']){
				characters[*i - 'a']=0;
				sum --;
				if (!sum) {
					printf("You win.\n");
					ok = 1;
					break;
				}
			}
			else {
				chance--;
				if (!chance){
					printf("You lose.\n");
					ok = 1;
					break;
				}
			}
		}
		if (!ok) printf("You chickened out.\n");
	}
	return 0;
}