#include <iostream>
#include <string>
#include <map>
using namespace std;
typedef struct node{
	string first;
	int fre;
}Morse;
typedef struct wnode{
	string word;
	int len;
	wnode(){}
	wnode(int l, string w) :len(l), word(w){}
}Word;
bool operator <(const Word& w1, const Word& w2){
	return w1.word < w2.word;
	//return w1.len < w2.len || w1.len == w2.len&&w1.word < w2.word;
}
int main(){
#ifdef LOCAL
	freopen("data.in", "r", stdin);
	freopen("data,out", "w", stdout);
#endif
	char c;
	string morse;
	map<char, string> letter;
	while (cin >> c&&c != '*'){
		cin >>morse;
		letter[c] = morse;
	}
	string word;
	map<Word, string> words;
	while (cin >> word&&word!="*"){
		string m = "";
		for (string::iterator iter = word.begin(); iter != word.end(); iter++){
			m += letter[*iter];
		}
		words[Word(word.length(),word)] = m;
	}
	map<string, Morse> morses;
	for (map<Word, string>::iterator iter = words.begin(); iter != words.end(); iter++){
		if (morses.count((*iter).second)) morses[(*iter).second].fre++;
		else{
			morses[(*iter).second].first = (*iter).first.word;
			morses[(*iter).second].fre=1;
		}
	}
	string item;
	while (cin >> item&&item != "*"){
		if (morses.count(item)) {
			cout << morses[item].first;
			if (morses[item].fre > 1) cout << "!";
			cout << endl;
		}
		else{
			map<string, Morse>::iterator min;
			int minl = 1000000;
			for (map<string, Morse>::iterator iter = morses.begin(); iter != morses.end(); iter++){
				string m = (*iter).first;
				if (item.find(m) == 0 || m.find(item) == 0){
					int l = item.length() < m.length() ? m.length() - item.length() : item.length() - m.length();
					if (l < minl){
						minl = l;
						min = iter;
					}
				}
			}
			if (minl < 1000000) cout << (*min).second.first << "?" << endl;
		}
	}
}