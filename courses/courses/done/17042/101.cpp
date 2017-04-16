#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<int> flat[25];
int n;
void find_pos(int block,int& flat_pos,int& pos){
	for (flat_pos = 0; flat_pos < n; flat_pos++){
		for (pos = 0; pos < flat[flat_pos].size(); pos++){
			if (flat[flat_pos][pos] == block) return;
		}
	}
}
void clear(int flat_pos,int pos){
	for (int i = pos+1; i < flat[flat_pos].size(); i++){
		flat[flat[flat_pos][i]].push_back(flat[flat_pos][i]);
	}
	flat[flat_pos].resize(pos + 1);
}
void pill_on(int flat1, int pos, int flat2){
	for (int i = pos ; i < flat[flat1].size(); i++){
		flat[flat2].push_back(flat[flat1][i]);
	}
	flat[flat1].resize(pos);
}
int main(){

	cin >> n;
	for (int i = 0; i < n; i++){
		flat[i].push_back(i);
	}
	string cmd1, cmd2;
	int block1, block2;
	while (cin >> cmd1&&cmd1 != "quit"){
		int flat1, flat2, pos1, pos2;
		cin >> block1 >> cmd2 >> block2;
		find_pos(block1, flat1, pos1);
		find_pos(block2, flat2, pos2);
		if (flat1 == flat2) continue;
		if (cmd1 == "move") clear(flat1, pos1);
		if (cmd2 == "onto") clear(flat2, pos2);
		pill_on(flat1, pos1, flat2);
	}
	for (int i = 0; i < n; i++){
		cout << i << ":";
		for (int j = 0; j < flat[i].size(); j++){
			cout << " " << flat[i][j];
		}
		cout << endl;
	}
}