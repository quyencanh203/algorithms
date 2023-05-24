#include<iostream>
using namespace std;

// Cấu trúc của một nút trong danh sách liên kết.
struct Node{
    int data;
    Node *next;
};

// Hàm khởi tạo một nút mới.
Node* createNode(int x){
    Node *p = new Node;
    p->data = x;
    p->next = NULL;
    return p;
}

// Hàm thêm một nút vào đầu danh sách.
Node* pushFront(Node *head, int x){
    Node *p = createNode(x);
    p->next = head;
    return p;
}

// Hàm in ra các giá trị trong danh sách liên kết.
void printList(Node *head){
    while(head != NULL){
        cout << head->data << " ";
        head = head->next;
    }
}

int main(){
    Node *head = NULL;
    int n;
    cout << "Nhap so luong can them qq: ";
    cin >> n;
    while(n--){
        int x;
        cout << "Nhap gia tri can them: ";
        cin >> x;
        head = pushFront(head, x);
    }
    printList(head);
    return 0;
}
