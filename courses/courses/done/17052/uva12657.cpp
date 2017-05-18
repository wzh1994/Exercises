#include <iostream>
#include <algorithm>
#define res(_i,_s,_n) for (int _i=_s;_i<_n;_i++)
using namespace std;
#define MAX 100100
#define link(_l,_r) right[(_l)]=(_r);left[(_r)]=(_l)
int main(){
#ifdef LOCAL
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif
	int n, m;
	int cas = 1;
	while (cin >> n >> m){
		int left[MAX];
		int right[MAX];
		int inv = 0;
		for (int i = 0; i < n; i++){
			link(i, i + 1);
		}
		link(n, 0);
		int op, x, y;
		while (m--){
			cin >> op;
			if (op == 4){
				inv = !inv;
			}
			else{
				cin >> x >> y;
				if (op == 3){
					if (right[y] == x) swap(x, y);
				}
				else if (inv) {
					op = 3 - op;
				}
				if (op == 1 && x == left[y] || op == 2 && x == right[y]) continue;
				int lx = left[x], rx = right[x], ly = left[y], ry = right[y];
				if (op == 1) {
					link(lx, rx);
					link(ly, x);
					link(x, y);
				}
				else if (op == 2){
					link(lx, rx);
					link(x, ry);
					link(y, x);
				}
				else if (op == 3){
					if (right[x] == y){
						link(lx, y);
						link(y, x);
						link(x, ry);
					}
					else{
						link(lx, y);
						link(y, rx);
						link(ly, x);
						link(x, ry);
					}
				}
			}
		}
		int now=0;
		long long sum=0;
		res(i, 0, n){
			now = right[now];
			if (i % 2 == 0)
				sum += now;
		}
		if (inv&&n % 2 == 0) sum = (long long)n*(n + 1) / 2 - sum;
		cout << "Case "<<cas++<<": " << sum << endl;
	}
}