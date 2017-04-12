#include <iostream>
#include <cstdio>
using namespace std;
typedef struct node{
	int number;
	struct node* prev;
	struct node* next;
}Queue,*QueueList;
int main(){
	int n, k, m;
	Queue queue[20];
	for (int i = 0; i < 20; i++){
		queue[i].number = i + 1;
	}
	while (cin >> n >> k >> m&&n*k*m!=0){
		for (int i = 0; i < n; i++){
			queue[i].prev = i>0?&queue[i - 1]:&queue[n-1];
			queue[i].next = i<n-1?&queue[i + 1]:queue;
		}
		int remain = n;
		QueueList head = queue;
		QueueList tail = &queue[n - 1];
		while (remain>0){
			//cout << " (" << remain << ") ";
			for (int i = 0; i < k%remain; i++){
				tail = tail->next;
			}
			for (int i = 0; i < m%remain; i++){
				head = head->prev;
			}
			if (head == tail){
				
				remain--;
				if (remain == 0) {
					printf("%3d\n", head->number);
					break;
				}
				else printf("%3d,", head->number);
				if (remain == 1) {
					printf("%3d\n", head->next->number);
					remain--;
					break;
				}
				head = head->next;
				tail = tail->prev;
				head->prev = tail;
				tail->next = head;
			}
			else{
				if (remain == 2){
					printf("%3d%3d\n", tail->number,head->number);
					remain -= 2;
					break;
				}
				else{
					printf("%3d%3d,", tail->number, head->number);
					tail = tail->prev;
					tail->next = tail->next->next;
					tail->next->prev = tail;
					if (head == tail){
						tail = tail->prev;
						head = head->next;
						tail->next = head;
						head->prev = tail;
					}
					else if (head->next == tail){
						tail->prev = head->prev;
						tail->prev->next = tail;
						head = tail;
					}
					else if (head->prev == tail){
						head = head->next;
						tail->next = head;
						head->prev = tail;
					}
					else{
						head = head->next;
						head->prev = head->prev->prev;
						head->prev->next = head;
					}
					remain -= 2;
				}
			}
		}
	}
}