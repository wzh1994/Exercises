#include <iostream>
#include <cstring>
using namespace std;
int main(){
	int N;
	cin >> N;
	int m, n;
	char DNAS[51][1005];
	int freq[4];
	int error;
	while (N--){
		memset(DNAS,0, sizeof(DNAS));
		cin >> m >> n;
		for (int i = 0; i < m ; i++)
			cin >> DNAS[i];
		error = 0;
		for (int j = 0; j < n; j++){
			memset(freq, 0, sizeof(freq));
			for (int i = 0; i < m; i++){
				if (DNAS[i][j] == 'A'){
					freq[0]++;
				}
				else if (DNAS[i][j] == 'C'){
					freq[1]++;
				}
				else if (DNAS[i][j] == 'G'){
					freq[2]++;
				}
				else {
					freq[3]++;
				}
			}
			int max = 0;
			for (int i = 1; i < 4; i++){
				if (freq[i]>freq[max]) max = i;
			}
			char ch = max == 0 ? 'A' : max == 1 ? 'C' : max == 2 ? 'G' : 'T';
			for (int i = 0; i < m; i++){
				if (DNAS[i][j] != ch) error++;
			}
			cout << ch;
		}
		cout << endl << error << endl;
	}
}