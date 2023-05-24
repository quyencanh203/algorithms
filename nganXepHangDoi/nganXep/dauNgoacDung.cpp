#include<iostream>
#include<stack>

using namespace std;

void check(stack <char> st, string s) {
	if (s[0] == ')') {
		cout << "invalid"<<endl;
		return ;
	}
	for (char x : s) {
		if (x == '(') {
			st.push(x);
		}
		if (x == ')') {
			if (st.empty()) {
				cout << "invalid"<<endl;
				return ;
			}
			st.pop();
		}
	}
	if (!st.empty()) cout << "invalid"<<endl;
	else cout << "valid"<<endl;
}

int main() {
	stack <char> st;
	string s;
	int n;
	cout << "enter so lan test : ";
	cin >> n;
	while (n--) {
		cout << "enter chuoi can test : ";
        cin >> s;
        check(st, s);
	}
	return 0;
}