#include <iostream>
#include <iomanip>
using namespace std;
int FinancialManagement(){
	double single,totle;
	totle = 0;
	for (int i = 0; i < 12; i++){
		cin >> single;
		totle += single;
	}
	cout << "$"<< setiosflags(ios::fixed)<<setprecision(2) << totle / 12;
	system("pause");
	return 0;
}