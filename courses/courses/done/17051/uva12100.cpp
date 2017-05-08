#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
typedef struct node{
	int num;
	int pre;
	int mine;
	node(){}
	node(int num, int pre, int mine = 0) :num(num), pre(pre), mine(mine){}
}Task;
int main(){
#ifdef LOCAL
	freopen("data.in", "r", stdin);
#endif
	int cases;
	cin >> cases;
	int pres[11];
	while (cases--){
		int n, m;
		cin >> n >> m;
		queue<Task> tasks;
		int pre;
		memset(pres, 0, sizeof(pres));
		for (int i = 0; i < n; i++){
			cin >> pre;
			pres[pre]++;
			if (i == m) tasks.push(Task(i, pre, 1));
			else tasks.push(Task(i, pre));
		}
		int ok = 0;
		int done = 0;
		for (int i = 9; i >0; i--){
			while (pres[i]&&!ok){
				Task t = tasks.front();
				if (t.pre == i){
					tasks.pop();
					++done;
					pres[i]--;
					if (t.mine){
						cout << done << endl;
						ok = 1;
					}
				}
				else{
					tasks.pop();
					tasks.push(t);
				}
			}
		}
	}
}