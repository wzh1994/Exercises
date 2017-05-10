#include <iostream>
using namespace std;
typedef unsigned long long LL;
int main(){
#ifdef LOCAL
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif
	long long n, sp, sq;
	while (cin >> n >> sp >> sq){
		LL ba=0, bb=0;
		LL best = (LL)1 << 61;
		for (LL i = 0; i < 32; i++){
			for (LL j = 0; j < 32; j++){
				LL cur = (((n - 1)*sp + ((n - 1)*sp << i)) >> j) + sq;
				if (cur>=n*sq&&cur < best){ 
					best = cur;
					ba = i;
					bb = j;
				}
			}
		}
		cout << best << " " << ba << " " << bb << endl;
	}
}