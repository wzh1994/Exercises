#include <iostream>
#include <string>
#include <set>
#define res(_i,_s,_n) for (int _i=_s;_i<_n;_i++)
using namespace std;
typedef struct node{
	string pos;
	string num;
	node(){};
	node(string p, string n) :pos(p), num(n){}
	bool operator <(const node& n)const{
		return pos.size() < n.pos.size() || pos.size() == n.pos.size() && pos < n.pos;
	}
}TNode;
int split(string s, string& num, string &pos);
int main(){
#ifdef LOCAL
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif
	string pair;
	string pos, num;
	set<TNode> tree;
	set<string> index;
	int ok = 1;
	while (cin >> pair){
		//cout << pair << endl;
		if (split(pair,num,pos)){
			TNode t(pos, num);
			if (index.count(pos)){
				ok = 0;
			}
			else{
				index.insert(pos);
				tree.insert(t);
			}
		}
		else{
			if (ok){
				set<string>::iterator it = index.begin();
				if (*it != "") ok = 0;
				else{
					for (it++; it != index.end(); it++){
						string s = (*it).substr(0, (*it).size() - 1);
						if (!index.count(s)){
							ok = 0;
							break;
						}
					}
				}
			}
			if (ok){
				for (set<TNode>::iterator it = tree.begin(); it != tree.end(); it++){
					if (it != tree.begin()) cout << " ";
					cout << (*it).num ;
				}
				cout << endl;
			}
			else{
				cout << "not complete" << endl;
			}
			tree.clear();
			index.clear();
			ok = 1;
		}
	}
}
int split(string s, string& num, string &pos){
	int p = s.find(",");
	if (p == -1) return 0;
	num = s.substr(1, p - 1);
	pos = s.substr(p + 1, s.size() - p - 2);
	return 1;
}