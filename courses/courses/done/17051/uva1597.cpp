#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <sstream>
#include <cctype>
using namespace std;
typedef struct node{
	int doc;
	int line;
	node(){}
	node(int d, int l) :doc(d), line(l){}
}Index;
bool operator <(const Index& i1, const Index& i2){
	return i1.doc < i2.doc || i1.doc == i2.doc&&i1.line < i2.line;
}
map<string, set<Index>> words;
vector<vector<string>> documents;
#define it (*iter)
int n;
void read();
int search(string word);
int search_and(string word1, string word2);
int search_or(string word1,string word2);
int search_not(string word);
int main(){
#ifdef LOCAL
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif
	read();
	int cmd_num;
	cin >> cmd_num;
	string cmd;
	getline(cin, cmd);
	while (cmd_num--){
		getline(cin, cmd);
		int result;
		if (cmd.find("AND")!=-1){
			istringstream s(cmd);
			string w1, w2;
			s >> w1 >> w2 >> w2;
			result=search_and(w1, w2);
		}
		else if (cmd.find("OR") !=-1){
			istringstream s(cmd);
			string w1, w2;
			s >> w1 >> w2 >> w2;
			result = search_or(w1, w2);
		}
		else if (cmd.find("NOT") == 0){
			istringstream s(cmd);
			string w1, w2;
			s >> w1 >> w2;
			result = search_not(w2);
		}
		else{
			result = search(cmd);
		}
		if (!result) cout << "Sorry, I found nothing."<<endl;
		cout << "=========="<<endl;
	}
}
void read(){
	string line;
	cin >> n;
	getline(cin, line);
	for (int i = 0; i < n; i++){
		vector<string> document;
		int l = 0;
		while (getline(cin, line) && line != "**********"){
			document.push_back(line);
			for (string::iterator iter = line.begin(); iter != line.end(); iter++){
				if (isalpha(*iter)) *iter = tolower(*iter);
				else *iter = ' ';
			}
			istringstream s(line);
			string word;
			while (s >> word){
				if (words.count(word)){
					words[word].insert(Index(i, l));
				}
				else{
					set<Index> s;
					s.insert(Index(i, l));
					words[word] = s;
				}
			}
			l++;
		}
		documents.push_back(document);
	}
}
int search(string word){
	if (words.count(word)){
		set<Index>::iterator iter = words[word].begin();
		int prevdoc = it.doc;
		cout << documents[it.doc][it.line]<<endl;
		for (iter++; iter != words[word].end(); iter++){
			if (it.doc != prevdoc) {
				prevdoc = it.doc;
				cout << "----------"<<endl;
			}
			cout << documents[it.doc][it.line] << endl;
		}
		return 1;
	}
	else
		return 0;
}
int search_and(string word1,string word2){
	vector<int> docs;
	set<Index> found;
	for (int i = 0; i < n; i++){
		docs.push_back(0);
	}
	if (words.count(word1)){
		for (set<Index>::iterator iter = words[word1].begin(); iter != words[word1].end(); iter++){
			docs[it.doc] = 1;
		}
	}
	if (words.count(word2)){
		for (set<Index>::iterator iter = words[word2].begin(); iter != words[word2].end(); iter++){
			if (docs[it.doc] == 1) docs[it.doc] = 2;
			if (docs[it.doc] == 2){
				found.insert(*iter);
			}
		}
	}
	if (words.count(word1)){
		for (set<Index>::iterator iter = words[word1].begin(); iter != words[word1].end(); iter++){
			if (docs[it.doc] == 2){
				found.insert(*iter);
			}
		}
	}
	if (!found.empty()){
		set<Index>::iterator iter = found.begin();
		int prevdoc = it.doc;
		cout << documents[it.doc][it.line] << endl;
		for (iter++; iter != found.end(); iter++){
			if (it.doc != prevdoc) {
				prevdoc = it.doc;
				cout << "----------" << endl;
			}
			cout << documents[it.doc][it.line] << endl;
		}
		return 1;
	}
	else
		return 0;
}
int search_or(string word1,string word2){
	set<Index> found;
	if (words.count(word1)){
		for (set<Index>::iterator iter = words[word1].begin(); iter != words[word1].end(); iter++){
			found.insert(*iter);
		}
	}
	if (words.count(word2)){
		for (set<Index>::iterator iter = words[word2].begin(); iter != words[word2].end(); iter++){
			found.insert(*iter);
		}
	}
	if (!found.empty()){
		set<Index>::iterator iter = found.begin();
		int prevdoc = it.doc;
		cout << documents[it.doc][it.line] << endl;
		for (iter++; iter != found.end(); iter++){
			if (it.doc != prevdoc) {
				prevdoc = it.doc;
				cout << "----------" << endl;
			}
			cout << documents[it.doc][it.line] << endl;
		}
		return 1;
	}
	else
		return 0;
}
int search_not(string word){
	vector<int> docs;
	for (int i = 0; i < n; i++)
		docs.push_back(1);
	if (words.count(word)){
		for (set<Index>::iterator iter = words[word].begin(); iter != words[word].end(); iter++){
			docs[it.doc] = 0;
		}
	}
	int remain = 0;
	for (int i = 0; i < n; i++){
		if (docs[i]>0){
			if (remain) cout << "----------" << endl;
			remain = 1;
			for (int j = 0; j < documents[i].size(); j++){
				cout << documents[i][j] << endl;
			}
		}
	}
	if (!remain)
		return 0;
	return 1;
}