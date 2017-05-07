#include <iostream>
#include <deque>
using namespace std;
int main(){
#ifdef LOCAL
	freopen("data.in", "r", stdin);
#endif
	int n;
	while (cin >> n&&n != 0){
		deque<int> list;
		while (n) list.push_front(n--); 
		cout << "Discarded cards:";
		while (list.size() > 1){
			cout << " " << list.front();
			list.pop_front();
			list.push_back(list.front());
			list.pop_front();
			if (list.size() > 1) cout << ",";
		}
		cout << endl << "Remaining card: " << list.front() << endl;
	}
}