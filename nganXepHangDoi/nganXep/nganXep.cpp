#include<iostream>
#include<stack> // thu vien stack
using namespace std;

//LIFO: last in first out
//push
//top 
//pop
// size
//empty
//O(1)

int main()
{
	stack <int> st;  //khai bao kieu du lieu stack cho st

	st.push(1); // dung st.push(kieu_du_lieu_khai_bao) de day 1 phan tu vao stack
	st.push(2);
	st.push(3);

	cout << st.top() << endl;  // dung st.top() de display phantu tren dau stack

	st.pop(); // dung st.pop()  de xoa phan tu tren dau stack nhu vi du la so 3 se bi xoa dau tien
	cout << st.top()<< endl; // sau khi xoa so 3 thi dung st.top() se display la 2
	st.pop();// nhu vay bay gio so 2 se bi xoa 
	cout << st.top()<< endl; // top cua stack bay gio la 1
	cout << st.size() << endl; // dung st.size() de check xem kich co cua stack hien tai la bao nhieu
	 //ta se tao ra doan code check empty 
	if (st.empty()) cout << "empty !" << endl;// tac dung cua no la check xem hien tai trong stack co bi rong hay khong

	return 0;
}