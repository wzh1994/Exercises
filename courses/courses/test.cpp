#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <map>
#include <iterator>
#include <windows.h>
#include <iomanip>
using namespace std;
double fun(double t){
	return log(1-2*t)-t+log(10);
}
void test(){
	double a=0.01, b=0.49;
	double a_y, b_y;//a_y<0,b_y>0
	a_y = fun(a);
	b_y = fun(b);
	double mid;
	double m_y;
	do{
		mid = (a + b) / 2;
		m_y = fun(mid);
		if (m_y < 0){
			b = mid;
			b_y = m_y;
		}
		else{
			a = mid;
			a_y = m_y;
		}
	} while (abs(b - a )> 1e-6);
	double result = sqrt(mid);
	cout << setiosflags(ios::fixed) << setprecision(10) << mid << endl << result;
}
