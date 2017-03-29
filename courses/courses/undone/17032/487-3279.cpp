//487-3279
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct numbers{
	int number;
	int repeat;
	struct numbers* next;
}Number,*NumberList;
int trans(char c);
int old_phone(){
	int totle;
	NumberList head=NULL;
	NumberList now,previous,tempNumber;
	scanf("%d", &totle);
	getchar();
	for (int i = 0; i < totle; i++){
		char c;
		int j = 0;
		int temp=0;
		while ((c = getchar()) != '\n'){
			if (c != '-') {
				temp *= 10;
				temp += trans(c);
			}
		}
		int found = 0;
		for (previous = NULL, now = head; now != NULL;){
			if (temp>now->number){
				previous = now;
				now = now->next;
			}
			else if (temp==now->number) {
				now->repeat++;
				found = 1;
				break;
			}
			else
				break;
		}
		if (!found) {
			tempNumber = (NumberList)malloc(sizeof(Number));
			tempNumber->number= temp;
			tempNumber->repeat = 1;
			tempNumber->next = now;
			if (previous!=NULL)previous->next = tempNumber;
			else head = tempNumber;
		}
	}
	int dup = 0;
	for (now = head; now != NULL;){
		if (now->repeat > 1){
			printf("%03d-%04d %d\n",now->number/10000,now->number%10000, now->repeat);
			dup = 1;
		}
		previous = now;
		now = now->next;
		free(previous);
	}
	if (!dup) printf("No duplicates.\n");
	return 0;
}
/*int trans(char c){
	if (c >= '0'&&c <= '9') return c-'0';
	if (c >= 'A'&&c <= 'Q') return 2 + (c - 'A') / 3;
	return 2 + (c - 'A'-1) / 3;
}*/