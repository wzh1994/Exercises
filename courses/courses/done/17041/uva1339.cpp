#include <iostream>
#include <string>
#include <sstream>
#include <cstring>
using namespace std;
int partition(int *arr, int start, int end){
	int p = start - 1;
	int q = start;
	int temp;
	for (; q < end; q++){
		if (arr[q] < arr[end]){
			++p;
			temp = arr[p];
			arr[p] = arr[q];
			arr[q] = temp;
		}
	}
	++p;
	temp = arr[p];
	arr[p] = arr[q];
	arr[q] = temp;
	return p;
}
void quicksort(int *arr, int start,int end){
	if (start >= end) return;
	int r = partition(arr, start, end);
	quicksort(arr, start, r-1);
	quicksort(arr, r + 1, end);
}
int main(){
	string str1,str2;
	int freq1[30],freq2[30];
	while (cin >> str1 >> str2){
		memset(freq1, 0, sizeof(freq1));
		memset(freq2, 0, sizeof(freq2));
		for (string::iterator i = str1.begin(); i != str1.end(); ++i){
			freq1[*i - 'A']++;
		}
		for (string::iterator i = str2.begin(); i != str2.end(); ++i){
			freq2[*i - 'A']++;
		}
		quicksort(freq1, 0, 25);
		quicksort(freq2, 0, 25);
		int ok = 1;
		for (int i = 0; i < 26; i++){
			if (freq1[i] != freq2[i]) {
				ok = 0;
				break;
			}
		}
		printf(ok ? "YES\n" : "NO\n");
	}
	return 0;
}