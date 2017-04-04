#include<cstdio>
int main(){
	int m, n;
	int r[3003],s[3003];
	//int cycle = 0;
	while (~scanf("%d%d", &m, &n)){
		//if (cycle++) printf("\n");
		printf("%d/%d = %d.",m,n, m / n);
		r[0] = m%n*10;
		s[0] = r[0] / n;
		int end = 1;
		int start = -1;
		if (r[0] == 0){
			start = 0;
			end = 1;
		}
		else {
			while (start < 0){
				r[end] = r[end - 1] % n * 10;
				s[end] = r[end] / n;
				if (r[end] == 0){
					start = end;
					end += 2;
					break;
				}
				for (int j = 0; j < end; j++){
					if (r[end] == r[j]) {
						start = j;
						break;
					}
				}
				end++;
			}
			end--;
		}
		int i;
		for (i = 0; i < start; i++)
			printf("%d", s[i]);
		printf("(");
		if (end - start <= 50) {
			for (i = start; i < end;i++)
				printf("%d", s[i]);
		}
		else{
			for (i = start; i < start + 50; i++)
				printf("%d", s[i]);
			printf("...");
		}
		printf(")\n");
		printf("   %d = number of digits in repeating cycle\n\n",end-start);
	}
}