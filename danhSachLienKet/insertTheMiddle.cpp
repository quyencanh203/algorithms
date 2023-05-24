#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *next = NULL;
};
typedef struct node node;
node *createOneNode(int x)
{
    node *newNode = new node;
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}

void pushBack(node *&head, node *newNode)
{
    node *temp = head;
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    return;
}

void pushFront(node *&head, node *newNode)
{
    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        newNode->next = head;
        head = newNode;
    }
}

void insert(node *&head, node *newNode, int k)
{
    node *temp = head;
    if (k == 1)
    {
        pushFront(head, newNode);
        return;
    }
    while (k--)
    {
        if (k == 1)
        {
            newNode->next = temp->next;
            temp->next = newNode;
            break;
        }
        temp = temp->next;
    }
}

void popFront(node *&head)
{
    if(head == NULL)
    return ;
    node *temp = head;
    head = head->next;
    delete temp;
    return;
}

void popBack(node *&head)
{
    node *temp = head;
    if(head == NULL)
    return ;
    if(temp->next == NULL)
    {
        head = NULL;
        delete temp;
    }
    while(temp->next->next != NULL)
    {
        temp = temp->next;
    }
    
    // node *t = temp->next;
    temp->next = NULL;
    // delete t;
}

void Delete(node *&head, int k)
{
    node *temp = head;
    if (k == 1)
    {
        popFront(head);
    }

    while (k--)
    {
        if(k == 1)
        {
            popBack(head);
        }
        if(k == 2)
        {
            node *t = temp->next;
            temp->next = t->next;
            delete t;
            break;
        }
        temp = temp->next;
    }
}

void printf(node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

void Menu(node *head)
{
    while (true)
    {

        cout << "\n\n\t\t================MENU================";
        cout << "\n\t1. pushBack.";
        cout << "\n\t2, pushFront.";
        cout << "\n\t3. printf link list: ";
        cout << "\n\t4. insert.";
        cout << "\n\t5. delete.";
        cout << "\n\t0. exit menu.";
        cout << "\n\t Your choice is: ";
        int choice;
        cin >> choice;
        if (choice == 1)
        {

            int x;
            cout << "\n enter value member : ";
            cin >> x;
            node *newNode = createOneNode(x);
            pushBack(head, newNode);
        }
        if (choice == 2)
        {

            int x;
            cout << "\n enter value member : ";
            cin >> x;
            node *newNode = createOneNode(x);
            pushFront(head, newNode);
        }
        if (choice == 3)
        {
            printf(head);
        }
        if (choice == 4)
        {
            int k;
            cout << "\n\t enter insert location : ";
            cin >> k;
            cout << "\n\t enter insert value : ";
            int x;
            cin >> x;
            node *newNode = createOneNode(x);
            insert(head, newNode, k);
        }
        if (choice == 5)
        {
            int k;
            cout << "\n\t enter delete location : ";
            cin >> k;
            Delete(head, k);
        }
        if (choice == 0)
        {
            cout << "\n\t You have successfully exitted!!!! ";
            break;
        }
    }
}

int main()
{
    node *head = NULL;
    Menu(head);
    return 0;
}