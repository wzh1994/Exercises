#include <iostream>
#include <algorithm> 
#include <set>
#include <stack>
#include <string>
#include <map>
#include <vector>
using namespace std;//必须在typedef之前
typedef set<int> Set;
map<Set, int> sid;
vector<Set> sets;
int getId(Set s){
	if (sid.count(s)) return sid[s];
	else {
		sets.push_back(s);
		return sid[s] = sets.size() - 1;
	}
}
int main(){
	int n;
	cin >> n;
	while (n--){
		int m;
		cin >> m;
		string cmd;
		stack<int> s;
		while (m--){
			cin >> cmd;
			if (cmd == "PUSH"){
				s.push(getId(Set()));
			}
			else if (cmd == "DUP"){
				s.push(s.top());
			}
			else {
				Set x1 = sets[s.top()];
				s.pop();
				Set x2 = sets[s.top()];
				s.pop();
				Set x;
				if (cmd == "UNION"){
					set_union(x1.begin(),x1.end(), x2.begin(), x2.end(), inserter(x,x.begin()));
				}
				else if (cmd == "INTERSECT"){
					set_intersection(x1.begin(), x1.end(), x2.begin(), x2.end(), inserter(x, x.begin()));
				}
				else if (cmd == "ADD"){
					x = x2;
					x.insert(getId(x1));
				}
				s.push(getId(x));
			}
			cout << sets[s.top()].size() << endl;
		}
		cout << "***" << endl;
	}
}