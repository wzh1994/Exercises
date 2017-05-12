#include <iostream>
#include <cstdio>
#include <string>
#include <set>
#include <map>
#include <algorithm> 
using namespace std;
#define res(_i,_s,_n) for (int _i=_s;_i<_n;_i++)
int main(){
#ifdef LOCAL
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif
	int n;
	cin >> n;
	string line;
	getline(cin, line);
	map<string, string> dic1, dic2;
	set<string> keys1, keys2;
	res(i,0, n){
		int pos, pos2;
		dic1.clear();
		dic2.clear();
		keys1.clear();
		keys2.clear();
		getline(cin, line);
		line = line.substr(1, line.size() - 2);
		while ((pos = line.find(':'))!=-1){
			if ((pos2 = line.find(',')) != -1){
				string key = line.substr(0, pos);
				string value = line.substr(pos + 1, pos2 - pos - 1);
				dic1[key] = value;
				line = line.substr(pos2+1);
			}
			else{
				string key = line.substr(0, pos);
				string value = line.substr(pos + 1);
				dic1[key] = value;
				line=line.substr(pos + 1);
			}
		}
		getline(cin, line);
		line = line.substr(1, line.size() - 2);
		while ((pos = line.find(':')) != -1){
			if ((pos2 = line.find(',')) != -1){
				string key = line.substr(0, pos);
				string value = line.substr(pos + 1, pos2 - pos - 1);
				dic2[key] = value;
				line = line.substr(pos2 + 1);
			}
			else{
				string key = line.substr(0, pos);
				string value = line.substr(pos + 1);
				dic2[key] = value;
				line = line.substr(pos + 1);
			}
		}
		for (map<string, string>::iterator iter = dic1.begin(); iter != dic1.end(); iter++){
			keys1.insert(iter->first);
		}
		for (map<string, string>::iterator iter = dic2.begin(); iter != dic2.end(); iter++){
			keys2.insert(iter->first);
		}
		int no = 1;
		set<string> dif;
		set_difference(keys2.begin(), keys2.end(), keys1.begin(), keys1.end(), inserter(dif,dif.begin()));
		if (!dif.empty()){
			cout << "+";
			no = 0;
			for (set<string>::iterator iter = dif.begin(); iter != dif.end(); iter++){
				if (iter != dif.begin()) cout << ',';
				cout << *iter;
			}
			cout << endl;
		}
		dif.clear();
		set_difference(keys1.begin(), keys1.end(), keys2.begin(), keys2.end(), inserter(dif, dif.begin()));
		if (!dif.empty()){
			cout << "-";
			no = 0;
			for (set<string>::iterator iter = dif.begin(); iter != dif.end(); iter++){
				if (iter != dif.begin()) cout << ',';
				cout << *iter;
			}
			cout << endl;
		}
		set<string> ins;
		set_intersection(keys1.begin(), keys1.end(), keys2.begin(), keys2.end(), inserter(ins, ins.begin()));
		if (!ins.empty()){
			int diff = 0;
			for (set<string>::iterator iter = ins.begin(); iter != ins.end(); iter++){
				if (dic1[*iter] != dic2[*iter]){
					no = 0;
					if (diff == 0){
						diff = 1;
						cout << "*";
					}
					else
						cout << ",";
					cout << *iter;
				}
			}
			if (diff) cout << endl;
		}
		if (no) cout << "No changes" << endl;
		cout << endl;
	}
}