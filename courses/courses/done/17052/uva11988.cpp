#include <iostream>
#include <string>
#include <cstdlib>
#define res(_i,_s,_n) for (int _i=_s;_i<_n;_i++)
using namespace std;
typedef struct node{
	char c;
	struct node* next;
	node(char c) :c(c), next(NULL){}
}LinkNode,*LinkList;
int main(){
#ifdef LOCAL
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif
	string line;
	while (getline(cin,line)){
		int l = line.length();
		int statue = 1;
		LinkList head=NULL;
		LinkList end=NULL;
		LinkList now=NULL;
		res(i, 0, l){
			if (line[i] == '['){
				if (!head) continue;
				statue = 1;
			}
			else if (line[i] == ']'){
				if (!head) continue;
				statue = 3;
			}
			else{
				LinkList p = (LinkList)malloc(sizeof(LinkNode));
				p->c = line[i];
				if (statue == 1){
					if (head==NULL){
						p->next = NULL;
						head = end = now = p;
					}
					else{
						p->next = head;
						head =now= p;
					}
					statue = 2;
				}
				else if (statue == 2){
					p->next = now->next;
					now->next = p;
					if (end == now) end = p;
					now = p;
				}
				else {
					p->next = NULL;
					end->next = p;
					end = p;
				}
			}
		}
		LinkList p;
		while (head != NULL){
			p = head;
			head = p->next;
			cout << p->c;
			free(p);
		}
		cout << endl;
	}
}