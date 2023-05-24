#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *pLeft;
    struct node *pRight;
};

void khoiTaoNode(struct node *&t)
{
    t = NULL;
}

void themNodeVaoCay(struct node *&t, int x)
{
    if (t == NULL)
    {
        struct node *p = new node();
        p->data = x;
        p->pLeft = NULL;
        p->pRight = NULL;
        t = p;
    }
    else
    {
        if (t->data > x)
        {
            themNodeVaoCay(t->pLeft, x);
        }

        if (t->data < x)
        {
            themNodeVaoCay(t->pRight, x);
        }
    }
}

void duyet_LNR(struct node *t)
{
    if (t != NULL)
    {
        duyet_LNR(t->pLeft);
        cout << t->data << " ";
        duyet_LNR(t->pRight);
    }
}

struct node *timkiem(struct node *t, int x)
{
    if (t == NULL)
    {
        return NULL;
    }
    else
    {
        if (x < t->data)
        {
            timkiem(t->pLeft, x);
        }
        else
        {
            if (x > t->data)
            {
                timkiem(t->pRight, x);
            }
            else
            {
                return t;
            }
        }
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
        cout << "\n3. tim kiem";
        cout << "\n0. ket thuc";
        cout << "\n\n\t\t======================";

        cout << "\nnhap luachon: ";
        cin >> luachon;
        if (luachon < 0 || luachon > 3)
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
                    duyet_LNR(t);
                }
                else
                {
                    if (luachon == 3)
                    {
                        int x;
                        cout << "\nnhap phan tu tim kiem: ";
                        cin >> x;
                        struct node *p = timkiem(t, x);
                        if (p == NULL)
                            cout << "\nkhong ton tai trong cay";
                        else
                            cout << "phan tu co ton tai";
                    }
                    else
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
}