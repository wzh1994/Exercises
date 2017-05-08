#include <iostream>
#include <cstdio>
#include <string>
#include <cctype>
#include <cmath>
#include <map>
using namespace std;
int getNum(int len) {
	int i = 0; 
	char c; 
	int num = 0;
	while (i < len){
		cin >> c; 
		if (isdigit(c)){
			num *=2;
			num += c-'0';
			i++;
		}
	}
	return num;
}
typedef struct node{
	int len;
	int value;
	node(){}
	node(int l, int v) :len(l), value(v){}
}Pair;
bool operator < (const Pair& p1, const Pair& p2){
	return p1.len < p2.len || p1.len == p2.len&&p1.value < p2.value;
}
using namespace std;
int main(){ 
#ifdef LOCAL
	freopen("data.in", "r", stdin);
#endif
	string chars;
	while (getline(cin,chars)){
		map<Pair,char> mapping;
		int i = 0;
		int l = 1;
		for (string::iterator it = chars.begin(); it != chars.end();it++){
			mapping[Pair(l, i++)] = *it;
			if (i == (pow(2,l)-1)) {
				i = 0;
				l++;
			}
		}
		int num;
		while (l=getNum(3)){
			while ((num = getNum(l))!=(pow(2,l)-1)){
				cout << mapping[Pair(l, num)];
			}
		}
		getline(cin, chars);
		cout << endl;
	}
}