#include <iostream>
#include <string>
#include <deque>
#include <queue>
#include <sstream>
#include <vector>
#include <map>
#define res(_i,_s,_n) for (int _i=_s;_i<_n;_i++)
using namespace std;
int main(){
#ifdef LOCAL
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif
	int N;
	cin >> N;
	res(cas, 0, N){
		if (cas) cout << endl;
		int time[6];
		int n;
		deque<int> exe;
		queue<int> wait;
		map<string, int> values;
		int lock = 0;
		vector<queue<string>> programs;
		cin >> n >> time[0] >> time[1] >> time[2] >> time[3] >> time[4] >> time[5];
		string cmd;
		getline(cin, cmd);
		res(i,0,n){
			queue<string> prog;
			while (getline(cin, cmd) ){
				prog.push(cmd);
				if (cmd.find("end") == 0) break;
			}
			programs.push_back(prog);
			exe.push_back(i);
		}
		while (!exe.empty()){
			int pronum= exe.front();
			exe.pop_front();
			int retime = time[5];
			//queue<string> prog = programs[pronum];
			int pb = 1;
			while (retime > 0){
				cmd = programs[pronum].front();
				istringstream ss(cmd);
				if (cmd.find("=") != -1){
					string key;
					string temp;
					int value;
					ss >> key >> temp >> value;
					values[key] = value;
					retime -= time[0];
				}
				else if (cmd.find("print") == 0){
					string key;
					string temp;
					ss >> temp >> key;
					cout << pronum+1 << ": " << values[key] << endl;
					retime -= time[1];
				}
				else if (cmd.find("lock") == 0){
					if (lock == 1){
						pb = 0;
						wait.push(pronum);
						break;
					}
					else{
						lock = 1;
						retime -= time[2];
					}
				}
				else if (cmd.find("unlock") == 0){
					lock = 0;
					if (!wait.empty()){
						int n = wait.front();
						wait.pop();
						exe.push_front(n);
					}
					retime -= time[3];
				}
				else if (cmd.find("end") == 0){
					pb = 0;
					break;
				}
				programs[pronum].pop();
			}
			if (pb) exe.push_back(pronum);
		}
	}

}