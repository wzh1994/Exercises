#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;
#define pos(_i,_j) (_i*n+_j)
int main(){
#ifdef LOCAL
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif
	int region[910];
	int cas = 1;
	int m, n;
	while (cin >> m >> n&&m*n != 0){
		cout << "Region " <<cas++ <<endl;
		for (int i = 0; i < m; i++){
			for (int j = 0; j < n; j++){
				cin >> region[pos(i, j)];
			}
		}
		int count = m*n;
		sort(region, region + count);
		int water;
		cin >> water;
		int lowest = 1;
		if (water == 0){
			cout << "Water level is " <<  setiosflags(ios::fixed) << setprecision(2) <<region[lowest-1]<< " meters." << endl << "0.00 percent of the region is under water." << endl << endl;
		}
		while (water>0){
			while (lowest < count&&region[lowest] == region[lowest - 1]) lowest++;
			if (lowest != count){
				int fall = region[lowest] - region[lowest - 1];
				if (fall*lowest*100 < water) {
					water -= fall*lowest * 100;
					for (int i = 0; i < lowest; i++){
						region[i] += fall;
					}
				}
				else {
					cout << "Water level is " << setiosflags(ios::fixed) << setprecision(2) << (region[lowest - 1] + (double)water / 100 / lowest) << " meters." << endl;
					cout << setiosflags(ios::fixed) << setprecision(2) << (double)lowest / count * 100 << " percent of the region is under water." << endl<<endl;
					break;
				}
			}
			else{
				cout << "Water level is " << setiosflags(ios::fixed) << setprecision(2) << (region[lowest - 1] + (double)water / 100 / lowest) << " meters." << endl;
				cout << setiosflags(ios::fixed) << setprecision(2) << (double)lowest / count * 100 << " percent of the region is under water." << endl << endl;
				break;
			}
		}
	}
}