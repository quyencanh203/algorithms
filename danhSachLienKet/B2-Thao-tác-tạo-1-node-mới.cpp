
#include <bits/stdc++.h>

using namespace std;

// cấu trúc của một node;
struct node
{
    int data;
    struct node *next;
};

// cấp phát tạo 1 node mới:
typedef struct node node; // dùng typedef để đặt cho struct node bằng node

node *makeNode(int x)
{
    // node *newNode = (node*)malloc(sizeof(node)); cấp phát động newNode theo C
    node *newNode = new node(); // cấp phát động theo c++
    /* vì newNode là kiểu con trỏ nên muốn truy cập vào từng thành phần của struct node thì
       phải dùng dấu -> chứ không được dung toán tử dot tứ dấu chấm
    */

    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}

int main()
{

    return 0;
}