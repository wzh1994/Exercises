#include <cstdio>
#include <cstring>
using namespace std;
short maxCommon[5000][5000];
int main(){
	int N;
	char number[5001];
	char reverse[5001];
	memset(maxCommon, 0, sizeof(maxCommon));
	scanf("%d", &N);
	getchar();
	N--;
	for (int i = 0; i <=N; i++){
		number[i] = reverse[N - i] = getchar();
	}
	number[N + 1] = reverse[N + 1] = '\0';
	for (int i = 0; i <= N; i++){
		maxCommon[0][i] = number[0] == reverse[i];
		maxCommon[i][0] = number[i] == reverse[0];
	}
	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= N; j++){
			if (number[i] == reverse[j]) maxCommon[i][j] = 1 + maxCommon[i - 1][j - 1];
			else maxCommon[i][j] = maxCommon[i][j - 1]>maxCommon[i - 1][j] ? maxCommon[i][j - 1] : maxCommon[i - 1][j];
		}
	}
	printf("%d", N - maxCommon[N][N] + 1);
}
