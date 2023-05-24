#include <iostream>
using namespace std;
//===============KHAI BAO CAU TRUC DANH SACH LIEN KET DON================
/**
 * cau truc mot node.
 */
struct node
{
    int data;           // chua du lieu cua mot node.
    struct node *pNext; // con tro lk dia chi cac node vs nhau.
};

typedef struct node NODE;
// khai bao cau truc cua dslk don.
struct list
{
    NODE *phead; // quan ly dau dslk.
    NODE *ptail; // quan ly cuoi dslk.
};
typedef struct list LIST; // thay the struc list thanh LIST.
//================KHOI TAO CAU TRUC DSLKD CAC SO NGUYEN================.
void khoiTao(LIST &l)
{
    // cho hai con tro tro den NULL, vi dslk chua co phan tu.
    l.phead = NULL;
    l.ptail = NULL;
}
// khoi tao mot cai node.
NODE *khoiTaoNODE(int x)
{
    NODE *p = new NODE; // cap phat dong.
    if (p == NULL)
    {
        cout << "\n khong du bo nho de cap phat !";
        return NULL;
    }
    p->data = x;     // truyen gia tri x vao data.
    p->pNext = NULL; // dau tien khai bao node thi node do chua lien ket node nao khac nen tro den NULL.
    return p;        // tra ve NODE p vua khoi tao.
}
// ham them vao dau dslk.
void themVaoDau(LIST &l, NODE *p)
{
    // ds dang rong.
    if (l.phead == NULL)
    {
        l.phead = l.ptail = p; // node dau cung chinh la node cuoi la p.
    }
    else
    {
        p->pNext = l.phead; // cho con tro cua node can them lien ket voi node dau cua phead.
        l.phead = p;        // cap nhap lai phead chinh la node can them.
    }
}

// ham them p vao cuoi dslk.
void themVaoCuoi(LIST &l, NODE *p)
{
    if (l.phead == NULL)
    {
        l.phead = l.ptail = p; // node dau cung chinh la node cuoi cung chinh la p.
    }
    else
    {
        l.ptail->pNext = p; // cho con tro ptail lien ket voi node p.
        l.ptail = p;        // cap nhap lai ptail la node p.
    }
}
// ham xuat dslk don.
void xuatDanhSach(LIST l)
{
    for (NODE *k = l.phead; k != NULL; k = k->pNext)
    {
        cout << k->data << " ";
    }
}

int main()
{
    LIST l;
    khoiTao(l); // khoi tao dslk don.
    int n;
    cout << "\n nhap so luong node can them: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cout << "\n nhap gia tri so nguyen: ";
        cin >> x;
        NODE *p = khoiTaoNODE(x); // khoi tao mot cai node so nguyen.
        themVaoDau(l, p);
    }
    cout << "\n\n\t danh sach lien ket don:\n";
    xuatDanhSach(l);
    system("pause");
    return 0;
}