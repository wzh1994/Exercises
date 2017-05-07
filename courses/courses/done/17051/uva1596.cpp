#include <iostream>
#include <map>
#include <set>
#include <cstdio>
#include <string>
#include <sstream>
#include <cctype>
typedef long long LL;
using namespace std;
typedef struct node{
	LL length;
	map<LL, LL> value;
	node() { }
	node(LL x, map<LL, LL> y) :length(x), value(y) { }
}IDentifier;
map<char, IDentifier> verbs;
int expression(LL& result, istringstream& s, char next);
int expression(LL& result, istringstream& s);
int number(LL& result, istringstream& s, char next);
int main(){
#ifdef LOCAL
	freopen("data.in", "r", stdin);
#endif
	string cmd;
	while (1){
		int line = 0;
		char id;
		char ch;
		verbs.clear();
		int right = 1;
		while (getline(cin, cmd)&&cmd!="."){
			line++;
			istringstream s(cmd);
			s >> id;
			s >> ch;
			//¸³Öµ
			if (verbs.count(id)){
				LL pos;
				if (!expression(pos, s, ']') || pos >= verbs[id].length){
					cout << line << endl;
					right = 0;
					while (getline(cin, cmd)&&cmd!=".");
					break;
				}
				s >> ch;
				LL result;
				if (!expression(result, s)){
					cout << line << endl;
					right = 0;
					while (getline(cin, cmd) && cmd != ".");
					break;
				}
				verbs[id].value[pos] = result;
			}
			//¶¨Òå
			else{
				LL len;
				if (!number(len, s, ']')) {
					cout << line << endl;
					right = 0;
					while (getline(cin, cmd) && cmd != ".");
					break;
				}
				map<LL, LL> mp;
				IDentifier ids(len,mp );
				verbs[id] = ids;
			}
		}
		if (line == 0) break;
		if (right) cout << "0" << endl;
	}
}
int number(LL& result, istringstream& s, char next){
	char ch;
	result = 0;
	while (s >> ch&&ch!=next){
		if (!isdigit(ch)) return 0;
		result *= 10;
		result += ch - '0';
	}
	return 1;
}
int expression(LL& result, istringstream& s){
	char ch;
	s >> ch;
	if (isdigit(ch)){
		result = ch - '0';
		while (s >> ch){
			if (!isdigit(ch)) return 0;
			result *= 10;
			result += ch - '0';
		}
		return 1;
	}
	else if (isalpha(ch)){
		char id = ch;
		s >> ch;
		LL r;
		if (!verbs.count(id) || !expression(r, s, ']') || r >= verbs[id].length || !verbs[id].value.count(r)) return 0;
		result = verbs[id].value[r];
		return 1;
	}
	else{
		return 0;
	}
}
int expression(LL& result, istringstream& s, char next){
	char ch;
	s >> ch;
	if (isdigit(ch)){
		result = ch - '0';
		while (s >> ch&&ch!=next){
			if (!isdigit(ch)) return 0;
			result *= 10;
			result += ch - '0';
		}
		return 1;
	}
	else if (isalpha(ch)){
		char id = ch;
		s >> ch;
		LL r;
		if (!verbs.count(id) || !expression(r, s, ']') || r >= verbs[id].length || !verbs[id].value.count(r)) return 0;
		result = verbs[id].value[r];
		while (s >> ch&&ch != next);
		return 1;
	}
	else{
		return 0;
	}
}