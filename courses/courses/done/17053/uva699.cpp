#include <iostream>
#include <cstring>
using namespace std;
#define MAXN 20001
int sum[MAXN];
void prt();
int getTree();
void build(int pos);
int main(){
#ifdef LOCAL
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif
	int cas = 1;
	while (getTree()){
		cout << "Case " << cas++ << ":" << endl;
		prt();
	}
}
void prt(){
	int p = 0;
	while (sum[p] == 0) p++;
	cout << sum[p++];
	while (sum[p] != 0) cout << " " << sum[p++];
	cout << endl<< endl;
}
int getTree(){
	int v;
	cin >> v;
	if (v == -1) return 0;
	memset(sum, 0, sizeof(sum));
	int pos = MAXN / 2;
	sum[pos] += v;
	build(pos - 1);
	build(pos + 1);
	return 1;
}
void build(int pos){
	int v;
	cin >> v;
	if (v == -1) return;
	sum[pos] += v;
	build(pos - 1);
	build(pos + 1);
}