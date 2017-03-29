#include <iostream>
using namespace std;
int Hangover(){
	float totle;
	int i;
	do{
		cin >> totle;
		if (totle == 0) break;
		float sum = 0;
		for (i = 2; sum < totle; i++)
			sum += (float)1 / i;
		cout << i - 2 << " card(s)"<< endl;
	} while (1);
	return 0;
}