#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
#define EX 0
#define DR 1
#define DC 2
#define IR 3
#define IC 4
#define it (*iter)
typedef struct node{
	int cmd;
	int r1, c1, r2, c2;
	int n,x[20];
	node(){
		cmd =r1=c1=r2=c2=n= 0;
		memset(x, 0, sizeof(x));
	}
}Cmd;
vector<Cmd> cmd;
int simulate(int& r, int& c);
int main(){
#ifdef LOCAL
	freopen("data.in", "r", stdin);
#endif
	int r, c, n;
	int cas = 0;
	while (scanf("%d%d%d", &r, &c, &n) == 3&&r>0&&c>0){
		char ex[5];
		cmd.clear();
		while (n--){
			Cmd c;
			scanf("%s", ex);
			if (ex[0] == 'E'){
				c.cmd = EX;
				scanf("%d%d%d%d", &c.r1, &c.c1, &c.r2, &c.c2);
			}
			else if (ex[0] == 'D'){
				if (ex[1] == 'R') c.cmd = DR;
				else c.cmd = DC;
				scanf("%d", &c.n);
				for (int i = 0; i < c.n; i++){
					scanf("%d", &c.x[i]);
				}
			}
			else if (ex[0] == 'I'){
				if (ex[1] == 'R') c.cmd = IR;
				else c.cmd = IC;
				scanf("%d", &c.n);
				for (int i = 0; i < c.n; i++){
					scanf("%d", &c.x[i]);
				}
			}
			cmd.push_back(c);
		}
		if (cas++) printf("\n");
		printf("Spreadsheet #%d\n", cas);
		scanf("%d", &n);
		while (n--){
			scanf("%d%d", &r, &c);
			printf("Cell data in (%d,%d) ", r, c);
			if (simulate(r, c)){
				printf("moved to (%d,%d)\n", r, c);
			}
			else
				printf("GONE\n");

		}
	}
}
int simulate(int& r, int& c){
	for (vector<Cmd>::iterator iter = cmd.begin(); iter != cmd.end(); iter++){
		if (it.cmd == EX){
			if (it.r1 == r&&it.c1 == c){ r = it.r2; c = it.c2; }
			else if (it.r2 == r&&it.c2 == c){ r = it.r1; c = it.c1; }
		}
		int dr = 0, dc = 0;
		if (it.cmd == IR){
			for (int i = 0; i < it.n; i++){
				if (it.x[i] <= r) dr++;
			}
		}
		if (it.cmd == IC){
			for (int i = 0; i < it.n; i++){
				if (it.x[i] <= c) dc++;
			}
		}
		if (it.cmd == DR){
			for (int i = 0; i < it.n; i++){
				if (it.x[i] == r) return 0;
				if (it.x[i] < r) dr--;
			}
		}
		if (it.cmd == DC){
			for (int i = 0; i < it.n; i++){
				if (it.x[i] == c) return 0;
				if (it.x[i] < c) dc--;
			}
		}
		r += dr;
		c += dc;
	}
	return 1;
}