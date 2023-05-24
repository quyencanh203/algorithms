#include<bits/stdc++.h>

using namespace std;
/*
   FIFO : first in first out
   O(1);
   push
   pop
   empty
   size
   front
*/

int main(){
    // khai bao mot ngan xep
    queue <int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    // bay gio in ra ta se thay phan tu dau hang doi la 1
    cout<<q.front()<<endl;
    // xoa phan tu dau queue
    q.pop();
    // current phan tu dau queue la 2
    cout<<q.front()<<endl;
    // ta se in ra do dai cua queue con lai
    cout<<q.size()<<endl; // dung vay do dai hien tai cua no la 3
    q.pop();
    q.pop();
    q.pop();
    // current ta check xem queue co empty hay khong
    cout<<q.empty()<<endl;
    // neu rong se in ra 1 nguoc lai 0
    return 0;
}