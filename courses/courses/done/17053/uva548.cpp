#include <iostream>
#include <string>
#include <sstream>
#define MAX 10010
using namespace std;
int inorder[MAX];
int postorder[MAX];
int cnt;
int minsum;
int minleaf;
int getNumber(int *arr);
void buildTree(int is, int ie, int ps, int pe,int sum);
int main(){
#ifdef LOCAL
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif
	int i;
	while (getNumber(inorder)){
		getNumber(postorder);
		minsum = 1e8;
		minleaf = MAX;
		buildTree(0, cnt, 0, cnt,0);
		cout << minleaf << endl;
	}
}
int getNumber(int *arr){
	string line;
	if (!getline(cin, line)) return 0;
	istringstream ss(line);
	cnt = 0;
	while (ss >> arr[cnt]) cnt++;
	cnt--;
	return 1;
}
void buildTree(int is, int ie,int ps,int pe,int sum){
	if (is > ie) return;
	if (is == ie){
		sum += inorder[is];
		if (sum < minsum || sum == minsum&& inorder[is] < minleaf){
			minsum = sum;
			minleaf = inorder[is];
		}
	}
	else{
		int head = postorder[pe];
		int pos=is;
		while (inorder[pos] != head&&is <= ie){
			pos++;
		}
		sum += inorder[pos];
		int leftNum = pos - is;
		buildTree(is, pos - 1, ps,ps+leftNum-1,sum);
		buildTree(pos+1, ie,ps+leftNum,pe-1,sum);
	}
}