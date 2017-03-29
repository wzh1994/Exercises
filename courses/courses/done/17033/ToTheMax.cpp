#include <iostream>
#include <cstring>
#include <climits>
using namespace std;
#define MAX(_a,_b) _a>_b?_a:_b
#define MAX3I(_a,_b,_c) MAX(_a,(MAX(_b,_c)))
int findMaxSubseq(int *array, int start, int end);
int main(){
	int N;
	cin >> N;
	int number[110][110];
	int sum[110];
	int max = INT_MIN;
	int i, j;
	for (i = 0; i < N; i++){
		for (j = 0; j < N; j++){
			cin >> number[i][j];
		}
	}
	for (i = 0; i < N; i++){
		for (j = i; j < N; j++){
			memset(sum, 0, 110 * sizeof(int));
			for (int k = i; k <= j; k++){
				for (int m = 0; m < N; m++){
					sum[m] += number[k][m];
				}
			}
			int result = findMaxSubseq(sum, 0, N - 1);
			max = MAX(max, result);
		}
	}
	cout << max;
}
int findMaxSubseq(int *array, int start, int end){
	if (start == end) return array[start];
	int mid = (start + end) / 2;
	int s1 = findMaxSubseq(array, start, mid);
	int s2 = findMaxSubseq(array, mid+1, end);
	int maxl = array[mid];
	int maxr = array[mid + 1];
	int suml = 0;
	int sumr = 0;
	for (int i = mid; i >= start; i--){
		suml += array[i];
		maxl = MAX(maxl, suml);
	}
	for (int i = mid+1; i <= end; i++){
		sumr += array[i];
		maxr = MAX(maxr, sumr);
	}
	int s3 = maxl + maxr;
	return MAX3I(s1, s2, s3);
}