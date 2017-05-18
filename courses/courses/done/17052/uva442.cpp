#include <iostream>
#include <map>
#include <string>
#include <stack>
typedef struct node{
	int row;
	int col;
	int count;
	int err;
	node(){}
	node(int e):row(0), col(0), count(0), err(1){}
	node(int r, int c) :row(r), col(c), count(0),err(0){}
	node(int r, int c, int count) :row(r), col(c), count(count),err(0){}
	node operator *(const node& m)const{
		if (col != m.row){
			return node(1);
		}
		int c = 0;
		c += count + m.count;
		c += row*col*m.col;
		return node(row, m.col, c);
	}
}Matrix;
#define res(_i,_s,_n) for (int _i=_s;_i<_n;_i++)
using namespace std;
int main(){
#ifdef LOCAL
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif
	int n;
	cin >> n;
	map<char, Matrix> matrices;
	char c;
	int col, row;
	while (n--){
		cin >> c >> row >> col;
		matrices[c] = Matrix(row, col);
	}
	string exp;//expression
	stack<Matrix> s;
	getline(cin, exp);
	while (getline(cin, exp)){
		int ok = 1;
		res(i, 0, exp.size()){
			char c = exp[i];
			if (c == '(') continue;
			else if (c == ')') {
				Matrix m2 = s.top();
				s.pop();
				Matrix m1 = s.top();
				s.pop();
				Matrix m3 = m1*m2;
				if (m3.err){
					ok = 0;
					break;
				}
				s.push(m3);
			}
			else{
				s.push(matrices[c]);
			}
		}
		if (ok){
			Matrix m = s.top();
			cout << m.count << endl;
			s.pop();
		}
		else{
			cout << "error" << endl;
		}
	}
}