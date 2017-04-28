#include <iostream>
#include <set>
using namespace std;
typedef long long LL;
int main(){
	set<LL> s;
	s.insert(1);
	for (int i = 1;; i++){
		LL x = *s.begin();
		if (i == 1500) {
			cout << "The 1500'th ugly number is " << x << "." << endl;
			break;
		}
		s.insert(2 * x);
		s.insert(3 * x);
		s.insert(5 * x);
		s.erase(s.begin());
	}
}