#include <iostream>
using namespace std;
int test(){
	int a[10] = {1,2,3,4,5,7,8,9,10,11};
	int b = 1;
	cout << a[b = 2];
	return 1;
}