#include <iostream>
using namespace std;
int main(){
	int p, e, i, d;
	int count = 1;
	while (1){
		cin >> p >> e >> i >> d;
		if (p < 0) break;
		p = p % 23;
		e = e % 28;
		i = i % 33;
		int n = i;
		while ((n-e)%28!=0)
		{
			n += 33;
		}
		while ((n - p) % 23 != 0){
			n += 924;
		}
		n = n-d <= 0 ? 21252+n-d : n-d;
		cout << "Case " << count << ": the next triple peak occurs in " << n << " days."<<endl;
		count++;
	}
	return 0;
}