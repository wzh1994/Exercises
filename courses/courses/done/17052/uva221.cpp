#include <iostream>
#include <set>
#include <vector>
using namespace std;
#define res(_i,_s,_n) for(int _i=_s;_i<_n;_i++)
typedef struct node{
	int id;
	double x, y, w, d, h;
	bool operator <(const node& b)const{
		return x < b.x || x == b.x&&y < b.y;
	}
	node(){}
	node(int id, double x, double y, double w, double d, double h) :id(id), x(x), y(y), w(w), d(d), h(h){}
}Building;
int n;
set<Building> buildings;
set<double> oxs;
vector<double> xs;
int isVis(Building b, double x);
int main(){
#ifdef LOCAL
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif
	int cyc = 0;
	while (cin >> n && n){
		if (cyc++) cout << endl;
		cout << "For map #"<<cyc<<", the visible buildings are numbered as follows:" << endl;
		buildings.clear();
		oxs.clear();
		xs.clear();
		double x, y, w, d, h;
		res(i, 0, n){
			cin >> x >> y >> w >> d >> h;
			buildings.insert(Building(i + 1, x, y, w, d, h));
			oxs.insert(x);
			oxs.insert(x + w);
		}
		set<double>::iterator x_iter = oxs.begin();
		double x_store = *x_iter;
		for (x_iter++; x_iter != oxs.end(); x_iter++){
			xs.push_back((x_store + *x_iter) / 2);
			x_store = *x_iter;
		}
		int v_num = 0;
		for (set<Building>::iterator b = buildings.begin(); b != buildings.end(); b++){
			int visiable = 0;
			res(i, 0, xs.size()){
				if (isVis(*b,xs[i])){
					visiable = 1;
					break;
				}
			}
			if (visiable) {
				if (v_num++) cout << " ";
				cout << b->id;
			}
		}
		cout << endl;
	}
}
int isVis(Building b, double x){
	if (b.x > x || b.x + b.w < x) return 0;
	for (set<Building>::iterator b2 = buildings.begin(); b2 != buildings.end(); b2++){
		if (b2->x <= x && b2->x + b2->w >= x&&b2->y<b.y&&b2->h>=b.h) return 0;
	}
	return 1;
}