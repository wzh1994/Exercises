#include <iostream>
#include <set>
#include <string>
#include <cstring>
using namespace std;
int main(){
#ifdef LOCAL
	freopen("data.in", "r", stdin);
#endif
	set<string> words;
	string word;
	set<string> puts;
	while (cin >> word) words.insert(word);
	set<string>::iterator end = words.end();
	end--;
	for (set<string>::iterator iter = words.begin(); iter != end; iter++){
		set<string>::iterator it = iter;
		for (it++; it != words.end(); it++){
			if ((*it).find(*iter) == 0){
				string s = (*it).substr((*iter).size(), (*it).size() - (*iter).size());
				if (words.count(s)) puts.insert(*it);
			}
			else{
				break;
			}
		}
	}
	for (set<string>::iterator iter = puts.begin(); iter != puts.end(); iter++){
		cout << *iter << endl;
	}
	/*
	for (set<string>::iterator iter = words.begin(); iter != words.end(); iter++){
		int len = (*iter).size()-1;
		for (int i = 0; i < len; i++){
			string s1 = (*iter).substr(0, i+1);
			if (!words.count(s1))continue;
			string s2 = (*iter).substr(i+1);
			if (!words.count(s2)) continue;
			cout << *iter << endl;
		}
	}
	*/
}