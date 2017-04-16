#include <iostream>
#include <sstream>
#include <string>
#include <set>
using namespace std;
int main(){
	string buff;
	string word;
	set<string> words;
	while (cin >> buff){
		for (int i = 0; i < buff.size(); i++){
			if (isalpha(buff[i])) buff[i] = tolower(buff[i]);
			else buff[i] = ' ';
		}
		stringstream ss(buff);
		while (ss >> word) words.insert(word);
	}
	for (set<string>::iterator i = words.begin(); i != words.end(); i++){
		cout << *i << endl;
	}
}