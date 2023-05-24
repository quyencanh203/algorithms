#include<bits/stdc++.h>
using namespace std;
// chuong trinh da bi loi can sua lai
// toi da thay doi roi ma huhu

void bubbleSort(int a[], int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(a[j] > a[j+1])
            {
                swap(a[j], a[j+1]);
            }
        } 
    }
}
void print(int a[], int n)
{
    for(int i=0; i<n; i++)
    {
        cout<<a[i]<<" ";
    }
}

int main(){

    int n; 
    cout<< "nhap so luong phan tu trong mang: ";
    cin>>n;
    int a[100];
    cout<<"\n bat dau nhap cac phan tu mang: \n";
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    bubbleSort(a,n);
    print(a,n);
    system("pause");
    return 0;
}
/**
 *  Sắp xếp nổi bọt.
 * ý tưởng: mỗi bước lặp sắp xếp các phần tử kề nhau khi chúng chưa có thứ tự đúng.
*/