#include <iostream>
#include <cstdio>
#include <iomanip>
#include <cmath>
using namespace std;
int main(){
	long long ip_or;//所有ip"或"的结果
	long long ip_and;//所有ip"与"之后的结果
	long long ip_xor;//"与"与"或"的结果再求异或
	long long mask;//存储掩码
	long long segment;//存储网段
	int n;			 //循环读ip次数
	//暂存数据
	long long temp;
	long long num1, num2, num3, num4;
	char ch;

	while (cin >> n){
		//初始化
		cin >> num1 >> ch >> num2 >> ch >> num3 >> ch >> num4;
		temp = 0;
		temp += (num1 << 24) + (num2 << 16) + (num3 << 8) + num4;
		ip_or = ip_and = temp;
		while (--n){
			//读取所有的ip，求or和and
			cin >> num1 >> ch >> num2 >> ch >> num3 >> ch >> num4;
			temp = 0;
			temp += (num1 << 24) + (num2 << 16) + (num3 << 8) + num4 ;
			ip_or = ip_or | temp;
			ip_and = ip_and&temp;
		}
		//求xor
		ip_xor = ip_or^ip_and;
		//求出从左到右第一个不同的数字的位置（位置是从右往左数的）
		int bit = log2(ip_xor * 2 + 1);
		mask = 0xFFFFFFFF;
		//将掩码末尾的bit位置0
		mask = (mask >> bit) << bit;
		//网段是随便一个ip与掩码的按位与
		segment = ip_or&mask;
		//输出结果
		cout << ((segment >> 24) & 0x0FF) << "." << ((segment >> 16) & 0x0FF) << "." << ((segment >> 8) & 0x0FF) << "." << (segment & 0x0FF) << endl;
		cout << ((mask >> 24) & 0x0FF) << "." << ((mask >> 16) & 0x0FF) << "." << ((mask >> 8) & 0x0FF) << "." << (mask & 0x0FF) << endl;
	}
	return 0;
}