#include <iostream>
using namespace std;
int solve(int m, int n);
int main(){
	int t;
	int m, n;
	cin >> t;
	for (; t > 0; t--){
		cin >> m >> n;
		cout << solve(m, n) << endl;
	}
	
}
int solve(int m, int n){
	if (m == 1 || n == 1 || n == 0) return 1;
	if (m < n) return solve(m, m);
	return solve(m, n - 1) + solve(m - n, n);
}