#include <iostream>
#include <map>
#include <vector>
using namespace std;
int main(){
#ifdef LOCAL
	freopen("data.in", "r", stdin);
#endif
	int n;
	while (cin >> n&&n != 0){ 
		int x, y;
		map<vector<int>,int> ideas;
		while (n--){
			cin >> x >> y;
			vector<int> v;
			v.push_back(y);
			v.push_back(x);
			if (ideas.count(v)){
				if (ideas[v] == 1)
					ideas.erase(v);
				else
					ideas[v]--;
				continue;
			}
			v.clear();
			v.push_back(x);
			v.push_back(y);
			if (ideas.count(v)){
				ideas[v]++;
			}
			else
				ideas[v] = 1;
		}
		if (ideas.empty()) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}