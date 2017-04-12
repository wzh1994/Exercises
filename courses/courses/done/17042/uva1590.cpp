#include <iostream>
#include <cstdio>
#include <iomanip>
#include <cmath>
using namespace std;
int main(){
	long long ip_or;//����ip"��"�Ľ��
	long long ip_and;//����ip"��"֮��Ľ��
	long long ip_xor;//"��"��"��"�Ľ���������
	long long mask;//�洢����
	long long segment;//�洢����
	int n;			 //ѭ����ip����
	//�ݴ�����
	long long temp;
	long long num1, num2, num3, num4;
	char ch;

	while (cin >> n){
		//��ʼ��
		cin >> num1 >> ch >> num2 >> ch >> num3 >> ch >> num4;
		temp = 0;
		temp += (num1 << 24) + (num2 << 16) + (num3 << 8) + num4;
		ip_or = ip_and = temp;
		while (--n){
			//��ȡ���е�ip����or��and
			cin >> num1 >> ch >> num2 >> ch >> num3 >> ch >> num4;
			temp = 0;
			temp += (num1 << 24) + (num2 << 16) + (num3 << 8) + num4 ;
			ip_or = ip_or | temp;
			ip_and = ip_and&temp;
		}
		//��xor
		ip_xor = ip_or^ip_and;
		//��������ҵ�һ����ͬ�����ֵ�λ�ã�λ���Ǵ����������ģ�
		int bit = log2(ip_xor * 2 + 1);
		mask = 0xFFFFFFFF;
		//������ĩβ��bitλ��0
		mask = (mask >> bit) << bit;
		//���������һ��ip������İ�λ��
		segment = ip_or&mask;
		//������
		cout << ((segment >> 24) & 0x0FF) << "." << ((segment >> 16) & 0x0FF) << "." << ((segment >> 8) & 0x0FF) << "." << (segment & 0x0FF) << endl;
		cout << ((mask >> 24) & 0x0FF) << "." << ((mask >> 16) & 0x0FF) << "." << ((mask >> 8) & 0x0FF) << "." << (mask & 0x0FF) << endl;
	}
	return 0;
}