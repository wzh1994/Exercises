#include <cstdio>
int main(){
	int n;
	scanf("%d", &n);
	getchar();
	while (n--){
		int num = 0;
		double mass=0;
		double totle = 0;
		char str[100];
		scanf("%s", str);
		int i;
		for (i = 0; str[i] != '\0';i++){
			if (str[i] > 'A'&&str[i] < 'Z') {
				totle +=num>0?mass*num:mass;
				mass = str[i] == 'C' ? 12.01 : str[i] == 'H' ? 1.008 : str[i] == 'O' ? 16.00 : 14.01;
				num = 0;
			}
			else if (str[i] >= '0'&&str[i] <= '9'){
				num *= 10;
				num += str[i] - '0';
			}
		}
		totle += num>0 ? mass*num : mass;
		printf("%.3f\n", totle);
	}
}