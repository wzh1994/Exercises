#include <iostream>
#include <stack>
#define res(_i,_s,_n) for (int _i=_s;_i<_n;_i++)
using namespace std;
int main(){
#ifdef LOCAL
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif
	int n;
	int order[1010];
	while (cin >> n&&n){
		while (1){
			cin >> order[0];
			if (order[0] == 0) break;
			res(i, 1, n){
				cin >> order[i];
			}
			int a = 1, b = 0;
			stack<int> s;
			int ok = 1;
			while (b < n){
				if (a == order[b]) {
					a++; b++;
				}
				else if (!s.empty() && s.top() == order[b]){
					s.pop();
					b++;
				}
				else if (a <= n){
					s.push(a++);
				}
				else{
					ok = 0; break;
				}
			}
			if (ok) cout << "Yes" << endl;
			else cout << "No" << endl;
		}
	    cout << endl;
	}
}