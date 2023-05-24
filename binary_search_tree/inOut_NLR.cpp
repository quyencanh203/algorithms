#include <bits/stdc++.h>
using namespace std;
/*
  de bai: nhap vao cay nhi phan cac so nguyen. Xuat ra man hinh cac phan tu cua cay nhi phan
*/
// khai bao cau truc mot cai node.
struct node
{
    int data;            // du lieu cua node ==> du lieu ma node se luu tru.
    struct node *pLeft;  // node lk ben trai cua cay <=> cay con trai.
    struct node *pRight; // node lk ben phai cua cay <=> cay con phai.
};

typedef struct node NODE;
typedef NODE *TREE;

// khoi tao cay.
void khoiTaoCay(TREE &t)
{
    t = NULL; // cay rong.
}

// ham them phan tu x vao cay nhi phan.
void themNodeVaoCay(TREE &t, int x)
{
    // neu cay rong.
    if (t == NULL)
    {
        NODE *p = new NODE; // khoi tao mot node de them vao cay.
        p->data = x;        // them du lieu x vao data.
        p->pLeft = NULL;
        p->pRight = NULL;
        t = p; // node p chinh la root cua cay luon.
    }
    else // co ton tai phan tu trong tree.
    {
        // neu phan tu them vao ma nho hon node goc => them vao ben trai
        if (t->data > x)
        {
            themNodeVaoCay(t->pLeft, x); // duyet qua ben trai de them phan tu vao x
        }
        else // neu phan tu them vao lon hon node goc => them vao ben phai
        {
            themNodeVaoCay(t->pRight, x); // duyet qua ben phai de them phan tu x
        }
    }
}
// ham xuat cay nhi phan theo NLR.
void duyet_NLR(TREE t)
{
    // neu cay con phan tu thi tiep tuc duyet
    if (t != NULL)
    {
        cout << t->data << " "; // xuat du lieu trong node.
        duyet_NLR(t->pLeft);    // duyet qua trai.
        duyet_NLR(t->pRight);   // duyet qua phai.
    }
}
// ham nhap du lieu .
void Menu(TREE &t)
{
    while (true)
    {
        int luachon;
        cout << "\n\n\t\t========Menu==========";
        cout << "\n1. nhap du lieu";
        cout << "\n2. xuat du lieu cay theo NLR";
        cout << "\n0. ket thuc";
        cout << "\n\n\t\t======================";

        cout << "\nnhap luachon: ";
        cin >> luachon;
        if (luachon < 0 || luachon > 2)
        {
            cout << "\nluachon khong hop le!";
            system("pause");
        }
        else
        {
            if (luachon == 1)
            {
                int x;
                cout << "\nnhap so nguyen x: ";
                cin >> x;
                themNodeVaoCay(t, x);
            }
            else
            {
                if (luachon == 2)
                {
                    cout << "\nthu tu duyet NLR:\n";
                    duyet_NLR(t);
                }
                else
                {
                    return;
                }
            }
        }
    }
}

int main()
{
    TREE t;
    khoiTaoCay(t);
    Menu(t);
    return 0;
}