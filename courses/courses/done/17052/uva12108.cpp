#include <iostream>
using namespace std;
int main(){
#ifdef LOCAL
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif
	int a[10]; //awake
	int b[10]; //sleep
	int c[10]; //count
	int s[10]; //status 0--awake 1--sleep
	int n;
	int cas = 1;
	while (cin>>n&&n!=0)
	{
		for (int i = 0; i < n; i++){ 
			cin >> a[i] >> b[i] >> c[i];
			if (c[i]>a[i]){
				s[i] = 1;
				c[i] -= a[i];
			}
			else{
				s[i] = 0;
			}
		}
		int i;
		int sn;
		for (i = 1; i < 100000; i++){
			sn = 0;
			for (int j = 0; j < n; j++){
				if (s[j]>0)
					sn++;
			}
			if (sn == 0) break;
			for (int j = 0; j < n; j++){
				if (s[j] == 0){
					if (c[j] == a[j]){
						if (sn>n - sn){
							s[j] = 1;
						}
						c[j] = 1;
					}
					else{
						c[j]++;
					}
				}
				else if (s[j] == 1){
					if (c[j] == b[j]){
						c[j] = 1;
						s[j] = 0;
					}
					else{
						c[j]++;
					}
				}
			}
		}
		if (i == 100000) i = -1;
		cout << "Case " << cas++ << ": " << i << endl;
	}
}