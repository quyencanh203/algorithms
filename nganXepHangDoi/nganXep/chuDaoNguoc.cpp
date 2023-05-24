#include<iostream>
#include<stack>
#include<string>
#include <sstream>
using namespace std;

int main() {

	stack <string> st;// tạo khối stack

	string s;
	getline(cin, s);
	stringstream ss(s);
	string m;
	while (ss>>m) {
		st.push(m);
	}
	
	while ( !st.empty()) {
		 cout<<st.top()<<" ";
		 st.pop();
	}

	return 0;
}
