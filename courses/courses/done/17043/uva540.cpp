#include <iostream>
#include <map>
#include <queue>
using namespace std;
int main(){
#ifdef LOCAL
	freopen("data.in", "r", stdin);
#endif
	int team_num;
	int loop = 0;
	while (cin >> team_num&&team_num != 0){
		map<int,int> mem_team;
		queue<int> line;
		queue<int> team[1001];
		cout << "Scenario #" << ++loop << endl;
		for (int i = 0; i < team_num; i++){
			int numbers;
			cin >> numbers;
			for (int j = 0; j < numbers; j++){
				int member_no;
				cin >> member_no;
				mem_team[member_no] = i;
			}
		}
		char cmd[20];
		while (cin >> cmd){
			if (cmd[0] == 'E'){
				int number;
				cin >> number;
				int team_num = mem_team[number];
				if (team[team_num].empty()){
					line.push(team_num);
				}
				team[team_num].push(number);
			}
			else if (cmd[0] == 'D'){
				int team_num = line.front();
				cout << team[team_num].front()<<endl;
				team[team_num].pop();
				if (team[team_num].empty()){
					line.pop();
				}
			}
			else break;
		}
		cout << endl;
	}
}