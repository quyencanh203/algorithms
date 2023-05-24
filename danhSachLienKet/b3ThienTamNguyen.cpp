#include <iostream>
using namespace std;

// cau truc node.
struct node
{
    int data;
    struct node *next;
};
typedef struct node node;
// cau truc link list.
struct list
{
    node *phead;
    node *ptail;
};
typedef struct list list;
// khoi tao cau truc link list.
void createLinkList(list &l)
{
    // cho hai node dau va cuoi tro den vung nho rong.
    l.phead = NULL;
    l.ptail = NULL;
}
// tao 1 node.
node *createNewNode(int x)
{
    node *newNode = new node;
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}
// them vao dau.
void pushFront(list &l, node *newNode)
{
    if (l.phead == NULL)
    {
        l.phead = l.ptail = newNode;
    }
    else
    {
        newNode->next = l.phead; // cho tro dia chi cua newNode tro den dia chi cua node duoc l.head luu giu dia chi
        l.phead = newNode;       // cap nhap lai dia chi node dau link list cho l.head
    }
}
// them vao cuoi.
void pushBack(list &l, node *newNode)
{
    if (l.phead == NULL)
    {
        l.phead = l.ptail = newNode;
    }
    else
    {
        l.ptail->next = newNode; // cho phan tro den dia chi cua node duoc l.ptail quan li tro den node duoc them
        l.ptail = newNode;       // cap nhap lai node cuoi cung cua link list
    }
}
// in dslk.
void printf(list l)
{
    while (l.phead != NULL)
    {
        cout << l.phead->data << " ";
        l.phead = l.phead->next;
    }
}
// them node newNode vao sau node q.
// vai tro cua newNode nhu node p.
void themNode_p_VaoSauNode_q(list &l, node *p)
{
    int x;
    cout << "\n Nhap gia tri node q : ";
    cin >> x;
    node *q = createNewNode(x); // se them nodeThem vao sau node nay.
    // node q duoc tao ra co td dung nhu la bien nho chi co td luu data va ko co td nao khac.
    if (q->data == l.phead->data && l.phead->next == NULL) // duyet xem dslk co roi vao th ton tai 1 pt.
    {
        pushBack(l, p);
    }
    else // truong hop link list co nhieu phan tu.
    {
        // duyet de tim vi tri can them do la node q.
        for (node *k = l.phead; k != NULL; k = k->next)
        {
            if (k->data == q->data)
            {
                node *t = createNewNode(p->data);
                node *g = k->next; // tao con tro luu dia chi node sau node q.
                t->next = g;       // cho node p la node can them tro den node g.
                k->next = t;       // tao moi lien ket tu node q den node p.
            }
        }
    }
}

// menu.
void Menu(list &l)
{
    int luachon;
    while (true)
    {
        system("cls");
        cout << "\n\n\t\t=========== Menu ===========";
        cout << "\n\t1. Them node vao danh sach";
        cout << "\n\t2. Xuat danh sach lien ket don";
        cout << "\n\t3. Them p vao sau node q";
        cout << "\n\t0. Thoat";
        cout << "\n\n\t\t=========== End ============";

        cout << "\nNhap lua chon: ";
        cin >> luachon;
        if (luachon < 0 || luachon > 3)
        {
            cout << "\nLua chon khong hop le. Xin kiem tra lai !";
        }
        if (luachon == 1)
        {
            int x;
            cout << "\nNhap gia tri so nguyen: ";
            cin >> x;
            node *newNode = createNewNode(x); // tao node luu node moi tao ra de them.
            pushBack(l, newNode);             // thuc hien them vao cuoi.
        }
        else
        {
            if (luachon == 2)
            {
                printf(l);
                system("pause");
            }
            else
            {
                if (luachon == 3)
                {
                    int x;
                    cout << "\n Nhap gia tri can them: ";
                    cin >> x;
                    node *p = createNewNode(x);
                    themNode_p_VaoSauNode_q(l, p);
                }
                else
                {
                    break; // thoat ra vong lap hien tai.
                }
            }
        }
    }
}

int main()
{
    list l;
    createLinkList(l);

    Menu(l);
    system("pause");
    return 0;
}