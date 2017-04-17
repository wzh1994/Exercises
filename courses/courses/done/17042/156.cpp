#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
string getKey(string str){
	for (string::iterator i = str.begin(); i != str.end(); i++){
		*i = tolower(*i);
	}
	sort(str.begin(), str.end());
	return str;
}
int main(){
	string s;
	vector<string> words;
	map<string, int> fre;
	while (cin >> s&&s != "#"){
		words.push_back(s);
		string key = getKey(s);
		if (!fre.count(key)) fre[key] = 0;
		fre[key]++;
	}
	sort(words.begin(),words.end());
	for (vector<string>::iterator i = words.begin(); i != words.end(); i++){
		if (fre[getKey(*i)] == 1) cout << *i << endl;
	}
}
