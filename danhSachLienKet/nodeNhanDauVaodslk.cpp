#include <iostream>
using namespace std;

// cấu trúc của một node
struct node
{
    int data;
    struct node *next;
};

typedef struct node node; // thay thế struct node băng node
// khởi tạo cấp phát động một node
node *makeNode(int x)
{
    node *newNode = new node(); // cấp phát cho con tro kieu node
    // cao phat theo C: node *newNode = (node*)malloc(sizeof(node))'
    newNode->data = x;
    newNode->next = NULL;
    return  newNode;
}

// thao tác duyệt một dslk
/*
thao tác này sẽ không không làm thay đổi dslk
vì bản chất kiểu struct node đã tồn tại con trỏ node *next rồi
nên khi ta khai báo trong hàm duyet(node *node) thì nó sẽ như kiểu biến thông thường vs int hay double ...
nếu mà muốn thay đổi khi hàm kết thúc thì ta phải truyền con trỏ cho biến thường int hay doube ... hoặc truyền tham chiếu
nếu là con trỏ thì phải trỏ vào nó lần nữa
vd: cho hàm
void duyet( node* head) lưu ý struct head đã có 1 con trỏ
thì nó chạy sẽ k làm thay đổi gt dslk giống như duyet(int a) "duyet(int a) là hàm thông thường k liên quan đến dữ liệu bài này"
muốn thay đổi giá trị của biến khi kết lthúc hàm thì
duyet(node **head) và tg ứng duyet(int *a) hay truyền tham chiếu duyet(int &a)
*/
void duyet(node *head)
{
    while (head != NULL)
    {
        cout << head->data << ' '; // truy cập vào dữ liệu của node hiện tại
        head = head->next;         // giúp di chuyển con trỏ head từ node hiện tại sang node tiếp theo bằng cách lấy địa chỉ của node tiếp theo gán chính cho thằng head
        // tiếp tục quay lại vòng while tg tự như vậy khi nào gt trị head = NULL thì kết thúc lặp
    }
}

// hàm đếm số node trong dslk
int count(node *head)
{
    int dem = 0;
    while (head != NULL)
    {
        dem++;
        head = head->next;
    }
    return dem;
}

// hàm thêm node vào đầu dslk dung cho cả c++ và c

void pushFront(node **head, int x)
{
    node *newNode = makeNode(x);
    // Buoc1 : phan next của newNode => head
    newNode->next = *head; // *head => địa chỉ của node head trong dslk
    // Buoc 2 : cap nhap node head => newNode
    *head = newNode;
}

// hàm thêm vào đâu dslk dung cho c++ vì c không hỗ trợ tham chiếu
/*void pushFront2(node *&head, int x)
{
    node *newNode = makeNode(x);
    newNode->next = head;
    head = newNode;
}
*/

// LƯU Ý HÀM pushFront() muốn dùng thì có 2 cách 1 truyền con trỏ đến con trỏ
//                                               2 truyền con trỏ đến tham chiếu tròn c++

int main()
{
    node *head = NULL;
    for (int i = 1; i <= 5; i++)
    {
        pushFront(&head, i);
    }
    duyet(head);
    cout << count(head);
    return 0;
}   