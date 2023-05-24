#include <iostream>
// day la insertion sort blalalal
// tiep tuc thay doi nay
using namespace std;

void makeArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}

void printArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}


void insertionSort(int a[], int n)
{
    for (int i = 1; i < n; i++)  // duyet cac phan tu mang
    {
        int temp=a[i];  
        int j=i-1;
        while(temp<a[j]&&j>=0)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=temp;
    }
}

int main()
{

    int a[1000];
    int n;
    cin >> n;

    makeArray(a, n);

    insertionSort(a, n);
    printArray(a, n);
    return 0;
}