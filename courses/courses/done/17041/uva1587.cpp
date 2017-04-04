#include <cstdio>
#include <cstring>
int main(){
	int w, h;
	int num[12];
	int times[12];
	int diff = 0;
	int same = 0;
	int flag;
	while (scanf("%d %d", &w, &h) == 2){
		memset(num, 0, sizeof(num));
		memset(times,0,sizeof(times));
		int n = 5;
		diff = 0;
		same = 0;
		while (1){
			flag = 1;
			for (int i = 0; i < diff; i++){
				if (num[i] == w) {
					times[i]++;
					flag = 0;
				}
			}
			if (flag){
				num[diff] = w;
				times[diff] = 1;
				diff++;
			}
			flag = 1;
			for (int i = 0; i < diff; i++){
				if (num[i] == h) {
					times[i]++;
					flag = 0;
				}
			}
			if (flag){
				num[diff] = h;
				times[diff] = 1;
				diff++;
			}
			if (w == h) same++;
			--n;
			if (n < 0) break;
			scanf("%d %d", &w, &h);
		}
		//printf("%d %d\n",diff,same);
		if (diff>3) printf("IMPOSSIBLE\n");
		else if (diff == 3){
			if (times[0] == times[1] && times[2] == 4 && same == 0) printf("POSSIBLE\n");
			else printf("IMPOSSIBLE\n");
		}
		else if (diff == 2){
			if ((times[0] == 4 || times[0] == 8) && same == 2) printf("POSSIBLE\n");
			else printf("IMPOSSIBLE\n");
		}
		else
			printf("POSSIBLE\n");
	}
}