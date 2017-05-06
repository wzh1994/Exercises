#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
int main(){
#ifdef LOCAL
	freopen("data.in", "r", stdin);
#endif
	int T;
	cin >> T;
	while (T--){
		int N;
		cin >> N;
		map<int, vector<int>> dots;
		int x, y;
		while (N--){
			cin >> x >> y;
			if (dots.count(y)){
				dots[y].push_back(x);
			}
			else{
				vector<int> v;
				v.push_back(x);
				dots[y] = v;
			}
		}
		stack<double> mid;
		int yes = 1;
		for (map<int, vector<int>>::iterator iter = dots.begin(); iter != dots.end(); iter++){
			double m = 0;
			vector<int> v = (*iter).second;
			sort(v.begin(), v.end());
			int s = v.size() - 1;
			m = (v[s / 2] + v[s - s / 2]) / (double)2;
			for (int i = 0; i < s / 2; i++){
				int mm = (v[i] + v[s - i]) / (double)2;
				if (mm != m) {
					yes = 0;
					break;
				}
			}
			if (!mid.empty()){
				if (mid.top()!= m) yes = 0;
			}
			if (yes == 0) break;
			mid.push(m);
		}
		if (yes) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}