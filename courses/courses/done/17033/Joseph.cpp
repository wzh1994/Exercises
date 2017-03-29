#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;
typedef struct node{
	int good;
	struct node *next;
}People,*PeopleList;
int stor[15];
void init(PeopleList people[], int N);
int calculate(int N);
int main(){
	int N;
	memset(stor, 0, sizeof(stor));
	while (1){
		cin >> N;
		if (N == 0) break;
		cout << calculate(N)<<endl;
	}
}
int calculate(int N){
	if (stor[N] > 0) return stor[N];
	PeopleList people[30];
	int i;
	for (i= 0; i < N; i++){
		people[i] = (PeopleList)malloc(sizeof(People));
		people[i]->good = 1;
	}
	for (; i <2*N; i++){
		people[i] = (PeopleList)malloc(sizeof(People));
		people[i]->good = 0;
	}
	int result;
	for (int m = N + 1; 1; m++){
		if (m % (N + 1) != 0&&m % (N + 1) != 1) continue;
		init(people, 2 * N - 1);
		PeopleList now = people[2 * N - 1];
		int symbol= 1;
		for (int i = 0; i < N; i++){
			for (int j = 0; j < (m-1)%(2*N-i); j++){
				now = now->next;
			}
			if (now->next->good){
				symbol = 0;
				break;
			}
			else {
				now->next = now->next->next;
			}
		}
		if (symbol) {
			result = m;
			break;
		}
	}
	for (i = 0; i < 2 * N; i++){
		free(people[i]);
	}
	return stor[N]=result;
};
void init(PeopleList people[], int N){
	for (int i = 0; i < N ; i++){
		people[i]->next = people[i + 1];
	}
	people[N]->next = people[0];
}