#include <iostream>
#include <map>
#include <vector>
using namespace std;
int main(){
#ifdef LOCAL
	freopen("data.in", "r", stdin);
#endif
	int n;
	cin >> n;
	while (n--){
		int m;
		map<vector<int>, int> mp;
		vector<int> k;
		vector<int> z;
		int num;
		cin >> m;
		while (m--){
			cin >> num;
			k.push_back(num);
			z.push_back(0);
		}
		mp[z] = 0;
		for (int i = 1; i < 1050; i++){
			if (mp.count(k)){
				if (mp[k] == 0) cout << "ZERO" << endl;
				else cout << "LOOP" << endl;
				break;
			}
			mp[k] = i;
			int temp = k[0];
			int s = k.size();
			for (int i = 1; i < s; i++){
				k[i-1] = (k[i]>k[i - 1]) ? k[i] - k[i - 1] : k[i - 1] - k[i];
			}
			k[s-1] = (temp > k[s-1]) ? temp - k[s-1] : k[s-1] - temp;
		}
	}
}