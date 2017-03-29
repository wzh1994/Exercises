#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main(){
	char Tzolkin[20][10] = { "imix", "ik", "akbal", "kan", "chicchan", "cimi", "manik", "lamat", "muluk", "ok", "chuen", "eb", "ben", "ix", "mem", "cib", "caban", "eznab", "canac", "ahau" };
	char Haab[19][8] = { "pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol", "chen", "yax", "zac", "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu", "uayet" };
	int N;
	cin >> N;
	cout << N<<endl;
	for (int i = 0; i < N; i++){
		int day;
		char month[7];
		int year;
		int haabDay;
		int totalDay;
		int tzolkinYear;
		int tzolkinDay;
		scanf("%d", &day);
		getchar();
		getchar();
		int j=0;
		char temp;
		while ((temp = getchar()) != ' '||j==0){
			if (temp != '.'&&temp != ' ')
				month[j++] = temp;
		};
		month[j] = '\0';
		scanf("%d", &year);
		for (j = 0; j < 19; j++){
			if (strcmp(Haab[j], month) == 0){
				haabDay = 20 * j + day;
			}
		}
		totalDay = haabDay + 365 * year;
		tzolkinYear = totalDay / 260;
		tzolkinDay = totalDay % 260;
		cout << tzolkinDay % 13 +1<< " " << Tzolkin[tzolkinDay % 20] << " " << tzolkinYear << endl;
	}
}