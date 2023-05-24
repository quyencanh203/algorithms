#include <iostream>
using namespace std;

// cau truc node.
struct node
{
    int data;
    node *next;
};

// khoi tao mot node.
node *createNode(int x)
{
    node *newNode = new node;
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}

// them vao dau.
void pushFront(node *&head, node *newNode)
{
    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        newNode->next = head;// sau khi tro vao head thi newNode->next se quan ly node ma haed da quan ly
        head = newNode;// vi ta dung 1 con tro head de quan ly dslk nen head luon phai o dau dslk nen ta cap nhap lai dia chi moi ma head can quan ly.
    }
}

void pushBack(node *&head, node *newNode)
{
    node *temp = head;
    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// duyet dslk.

void duyet(node *head)
{
    while(head != NULL)
    {
        cout<<head->data<<" ";
        head = head->next;
    }
}

int main()
{
    // tao con tro luu dslk.
    node *head = NULL;
    int n;
    int i=0;
    cout<<" enter length of link list: ";
    cin>>n;
    while(n--)
    {
        int x;
        cout<<"enter element "<< i+1<<" : ";
        cin>>x;
        node *newNode = createNode(x);
        pushFront(head, newNode);
    }
    cout<<"link list : ";
    duyet(head);
    '\n';
    system("pause");
    return 0;
}
