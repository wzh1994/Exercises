#include <iostream>
using namespace std;
int isBalance();
int main(){
#ifdef LOCAL
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif
	int cas = 0;
	int n;
	cin >> n;
	for (cas = 0; cas < n; cas++){
		if (cas) cout << endl;
		if (isBalance()>0) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}
int isBalance(){
	int w1, d1, w2, d2;
	cin >> w1 >> d1 >> w2 >> d2;
	if (w1 == 0) w1 = isBalance();
	if (w2 == 0) w2 = isBalance();
	int result = ((w1*d1 == w2*d2) && (w1 != -1) && (w2 != -1)) ? w1+w2 : -1;
	return result;
}