#include <iostream>
#include <algorithm>
using namespace std;
int main(){
	int a[10000];
	int m, n;
	int loop = 1;
	while (cin >> m >> n&&m*n!=0){
		for (int i = 0; i < m; i++){
			cin >> a[i];
		}
		cout << "CASE# " << loop++ << ":" << endl;
		sort(a, a + m);
		int b;
		while (n--){
			cin >> b;
			int j;
			for (j = 0; j < m; j++){
				if (a[j] == b) break;
			}
			if (j < m) cout << b << " found at " << j+1 << endl;
			else cout << b << " not found" << endl;
		}
	}
}