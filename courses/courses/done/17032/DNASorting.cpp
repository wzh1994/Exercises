#include <iostream>
#include <stdlib.h>
using namespace std;
typedef struct node{
	char dna[51];
	int converse;
}DNA,*DNANode;
int compare(const void* a, const void* b);
void QiuckSort(DNANode *a, int p, int r);
int main(){
	int n, m;
	cin >> n >> m;
	DNANode DNAs[101];
	for (int i = 0; i < m; i++){
		DNAs[i] = (DNANode)malloc(sizeof(DNA));
		cin >> DNAs[i]->dna;
		int count = 0;
		int countG = 0;
		int countC = 0;
		int countA = 0;
		for (int j = n-1; j >=0 ; j--){
			switch (DNAs[i]->dna[j]){
			case 'T':
				count += countG + countC + countA;
				break;
			case 'G':
				countG++;
				count +=  countC + countA;
				break;
			case 'C':
				countC++;
				count += countA;
				break;
			case 'A':
				countA++;
				break;
			}
			DNAs[i]->converse = count;
		}
	}
	QiuckSort(DNAs, 0, m - 1);
	for (int i = 0; i < m; i++){
		cout << DNAs[i]->dna<<endl;
	}
}
void swq(DNANode &a, DNANode &b)
{
	DNANode t = a;
	a = b;
	b = t;
}
int Paratition(DNANode *a, int p, int r)
{
	int i = p - 1;
	for (int j = p; j<r; j++)
	if (a[j]->converse <= a[r]->converse)
	{
		i++;
		swq(a[j], a[i]);
	}
	swq(a[i + 1], a[r]);
	return i + 1;
}
void QiuckSort(DNANode a[], int p, int r)
{
	if (p >= r)
		return;
	int q = Paratition(a, p, r);
	QiuckSort(a, p, q - 1);
	QiuckSort(a, q + 1, r);
}