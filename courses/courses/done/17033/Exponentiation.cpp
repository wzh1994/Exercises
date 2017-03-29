#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
void swapValue(int *num_1, int *num_2);
void revmul(int *num_1, int *num_2, int* num_3);
int main(){
	char m[7];
	int n;
	int num[7];
	int result[151];
	int bcs[151];
	while (scanf("%s %d",&m,&n)!=EOF){
		int dot = -1;
		int i, j;
		for (i = 0, j = 1; i < 6; i++){
			if (m[i] == '.')
				dot = 5 - i;
			else{
				num[j++] = m[i] - '0';
			}
		};
		num[0] = j - 1;
		for (i = 1, j = num[0]; i < j; i++, j--){
			num[i] ^= num[j];
			num[j] ^= num[i];
			num[i] ^= num[j];
		}
		for (i = 0; i <= num[0]; i++){
			bcs[i] = num[i];
			result[i] = num[i];
		}
		for (i = 1; i < n; i++){
			revmul(bcs, num, result);
			for (j = 0; j <= result[0]; j++){
				bcs[j] = result[j];
			}
		}
		for (i = 1, j = result[0]; i < j; i++, j--){
			result[i] ^= result[j];
			result[j] ^= result[i];
			result[i] ^= result[j];
		}
		//È¥µôÄ©Î²µÄ0
		i = result[0];
		int dotpos = dot < 0 ? dot : result[0] - dot*n;
		//int dotpos = result[0] - dot*n;
		if (dotpos>=0) while (i > dotpos&&result[i] == 0) {
			result[0]--;
			i--;
		}
		i = 1;
		if (dotpos >= 0){
			while (i <= dotpos&&result[i] == 0) i++;
			if (i > dotpos) {
				if (i > result[0]) cout << "0";
				else cout << '.';
				for (; i <= result[0]; i++)
					cout << result[i];
			}
			else{
				for (; i <= dotpos; i++)
					cout << result[i];
				if (i <= result[0]) cout << '.';
				for (; i <= result[0]; i++)
					cout << result[i];
			}
			cout << endl;
		}
		else{
			while (result[i] == 0&&i<result[0]) i++;
			for (; i <= result[0]; i++)
				cout << result[i];
			cout << endl;
		}
	}
	
}
void revmul(int *num_1, int *num_2, int* num_3){
	memset(num_3, 0, 151 * sizeof(int));
	int i, j;

	for (i = 1; i<=num_1[0]; i++){
		for (j = 1; j<=num_2[0]; j++){
			num_3[i + j-1] += num_1[i] * num_2[j];
			if (num_3[i + j-1] > 9) {
				num_3[i + j ] += num_3[i + j-1] / 10;
				num_3[i + j-1] %= 10;
			}
		}
	}
	i--; 
	j--;
	if (num_3[i + j-1] > 9){
		num_3[i + j ] += num_3[i + j-1 ] / 10;
		num_3[i + j-1 ] %= 10;
	}
	if (num_3[i + j] > 0)
		num_3[0] = i+j;
	else
		num_3[0] = i+j-1;
	

}
void swapValue(int *num_1, int *num_2){
	char temp;
	temp = *num_2;
	*num_2 = *num_1;
	*num_1 = temp;
}