#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
using namespace std;
int main(){
	double A[20][40];
	long B[20][40];
	for (int i = 0; i < 10; i++){
		for (int j = 1; j < 31; j++){
			double t = log10(pow(2, i + 1) - 1) + ((pow(2, j) - i - 2)*log10(2));
			B[i][j] = t;
			A[i][j] = pow(10, t-B[i][j] );
			//cout <<"i="<<i<<" j="<<j<<" :"<< A[i][j] << " " << B[i][j] << endl;
		}
	}
	string ss;
	while(cin >> ss && ss != "0e0") {
		for (string::iterator i = ss.begin(); i != ss.end(); ++i){
			if (*i == 'e') *i = ' ';
		}
		istringstream is(ss);
		double m;
		int n;
		is >> m >> n;
		//cout<<ss<<": " << m << " " << n << endl;
		for (int i = 0; i <= 9; ++i) {
			for (int j = 1; j <= 30; ++j) {
				if (n == B[i][j] && (fabs(m - A[i][j]) < 1e-4 || fabs(m / 10 - A[i][j]) < 1e-4)) {
					cout << i << ' ' << j << endl;
					break;
				}
			}
		}
	}
	return 0;
}