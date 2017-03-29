#include <iostream>
using namespace std;
#define PI 3.141592653
int main(){
	int loop;
	cin >> loop;
	for (int i=1; i<=loop; i++){
		float x, y;
		cin >> x >> y;
		cout<<"Property "<<i<< ": This property will begin eroding in year "<< (int)(PI*(x*x + y*y) / 100+1)<<"."<<endl;
	}
	cout << "END OF OUTPUT."<<endl;
}
