// teck28
#include<iostream>
#include<stack> // khai bao thu vien stack

using namespace std;

int main()
{
	stack <int> st;
	int n;
	cin >> n;

	// tao vong lap chuyen doi so nhi phan
	while (n != 0)
	{
		st.push(n % 2); // push phan du sau khi chia vao stack
		n /= 2;
	}

	// tao vong lap hien thi ra so nhi phan da chuyen doi 
	while (!st.empty())
	{
		cout << st.top();
		st.pop();
	}

	return 0;
}