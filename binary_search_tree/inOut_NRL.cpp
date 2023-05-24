#include <iostream>
using namespace std;

struct node
{
    int data;            // du lieu ma node se luu tru
    struct node *pLeft;  // node lien ket ben trai
    struct node *pRight; // node lien ket ben phai
};

void khoiTaoNode(struct node *&t)
{
    t = NULL; // cay rong
}

void themNodeVaoCay(struct node *&t, int x)
{
    if (t == NULL) // neu cay rong
    {
        struct node *p = new node(); // tao mot node them vao cay
        p->data = x;
        p->pLeft = NULL;
        p->pRight = NULL;
        t = p; // node p la node goc cua cay hien tai
    }
    else
    {
        if (t->data > x)
        {
            themNodeVaoCay(t->pLeft, x); // them node vao ben trai
        }
        else
        {
            themNodeVaoCay(t->pRight, x); // them node vao ben phai
        }
    }
}

void duyet_NRL(struct node *t)
{
    if (t != NULL)
    {
        cout << t->data << " ";
        duyet_NRL(t->pRight);
        duyet_NRL(t->pLeft);
    }
}

void Menu(struct node *&t)
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
                    duyet_NRL(t);
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
    struct node *t = new node();
    khoiTaoNode(t);
    Menu(t);
    return 0;
}