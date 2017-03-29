#include <iostream>
using namespace std;
#define assert(_x) do{\
	if (!(_x)){\
		cout << "error"; \
		return 0; \
	}}\
	while (0)
int partition(int *array, int start, int end);
int quickSerch(int *array, int start, int end, int dst);
int main(){
	int N;
	cin >> N;
	int output[10000];
	for (int i = 0; i < N; i++)
		cin >> output[i];
	assert(quickSerch(output, 0, N-1, (N -1)/ 2) == (N -1)/ 2);
	cout << output[(N-1) / 2];
}
int partition(int *array, int start, int end){
	if (start == end) return start;
	int p , q ;
	for (p = start - 1, q = start; q < end; q++){
		if (array[q] < array[end]) {
			int temp = array[q];
			array[q] = array[++p];
			array[p] = temp;
		}
	}
	int temp = array[end];
	array[end] = array[++p];
	array[p] = temp;
	return p;
}
int quickSerch(int *array, int start, int end, int dst){
	int mid = partition(array, start, end);
	if (mid == dst) return mid;
	else if (mid > dst) return quickSerch(array, start, mid - 1, dst);
	else return quickSerch(array, mid+1,end, dst);
}