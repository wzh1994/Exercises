#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <map>
#define res(_i,_s,_n) for (int _i=_s;_i<_n;_i++)
using namespace std;
void getNameAndMta(string user, string& name, string& mta);
int main(){
#ifdef LOCAL
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif
	string temp;
	set<string> users;
	while (cin >> temp &&temp!= "*"){
		string mta;
		int u_num;
		cin >> mta>>u_num;
		string user;
		while (u_num--){
			cin >> user;
			users.insert(user + "@" + mta);
		}
	}
	string sender;
	string sname, smta;
	while (cin >> sender&&sender != "*"){
		getNameAndMta(sender, sname, smta);
		string receiver;
		string rname, rmta;
		vector<string> mtas;
		set<string> receivers;
		map<string, vector<string>> m_us;
		while (cin >> receiver&&receiver != "*"){
			if (receivers.count(receiver))continue;
			receivers.insert(receiver);
			getNameAndMta(receiver, rname, rmta);
			if (!m_us.count(rmta)){
				mtas.push_back(rmta);
				m_us[rmta] = vector<string>();
			}
			m_us[rmta].push_back(receiver);
		}
		getline(cin, temp);
		string data = "";
		while (getline(cin,temp)&&temp != "*"){
			data += "     " + temp + "\n";
		}
		data += "     .";
		res(i, 0, mtas.size()){
			string rmta = mtas[i];
			vector<string> us = m_us[rmta];
			cout << "Connection between " << smta << " and " << rmta << endl;
			cout << "     HELO " << smta<<endl<<"     250"<<endl;
			cout << "     MAIL FROM:<" << sender << ">" << endl<<"     250" << endl;
			int ok = 0;
			res(j, 0, us.size()){
				cout << "     RCPT TO:<" << us[j] << ">" << endl;
				if (users.count(us[j])){
					ok = 1;
					cout << "     250" << endl;
				}
				else{
					cout << "     550" << endl;
				}
			}
			if (ok) cout <<"     DATA"<<endl<<"     354"<<endl<< data << endl << "     250" << endl;
			cout << "     QUIT" << endl << "     221" << endl;
		}
	}
}
void getNameAndMta(string user, string& name, string& mta){
	int pos = user.find('@');
	name = user.substr(0, pos);
	mta = user.substr(pos+1);
}