#include <iostream>
#include <set>
#include <map>
#include <string>
using namespace std;
typedef struct node{
	string name;
	string author;
	node(){}
	node(string name, string author) :name(name), author(author){}
}Book;
typedef pair<set<Book>::iterator, bool> result;
bool operator < (const node& node1, const node& node2){
	return node1.author < node2.author || node1.author == node2.author&&node1.name < node2.name;
}
ostream& operator << (ostream&out, const node& node){
	out << "\""<<node.name<<"\"";
	return out;
}
int main(){
#ifdef LOCAL
	freopen("data.in", "r", stdin);
#endif
	string line;
	set<Book> books;
	set<Book> returns;
	map<string, Book>names;
	while (getline(cin, line)&&line!="END"){
		string name = line.substr(1, line.find('\"', 2) - 1);
		string author = line.substr(line.find('\"', 2) + 1).substr(4);
		Book book(name, author);
		books.insert(book);
		names[name] = book;
	}
	while (getline(cin, line) && line != "END"){
		if (line[0] == 'B'){
			string name = line.substr(8, line.size() - 9);
			books.erase(names[name]);
		}
		else if (line[0] == 'R'){
			string name = line.substr(8, line.size() - 9);
			returns.insert(names[name]);
		}
		else if (line[0] == 'S')
		{
			for (set<Book>::iterator iter = returns.begin(); iter != returns.end(); iter++){
				result r = books.insert(*iter);
				set<Book>::iterator it = r.first;
				if (it == books.begin()){
					cout << "Put " << *iter << " first"<<endl;
				}
				else{
					it--;
					cout << "Put " << *iter << " after " << *it<<endl;
				}
			}
			returns.clear();
			cout << "END" << endl;
		}
	}
}