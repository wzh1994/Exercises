#include <iostream>
#include <cstring>
#define res(_i,_s,_n) for (int _i=_s;_i<_n;_i++)
using namespace std;
int main(){
#ifdef LOCAL
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif
	int N;
	int d, n;
	cin >> N;
	while (N--){
		cin >> d >> n;
		int p;
		p = 1;
		for (int i = 1; i < d; i++){
			if (n % 2){
				n = (n + 1) / 2;
				p = 2 * p;
			}
			else{
				n = n / 2;
				p = 2 * p + 1;
			}
		}
		cout << p << endl;
	}
	
}