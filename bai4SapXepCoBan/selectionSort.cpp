#include <iostream>

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

/*
ý tưởng :
   Duyệt mảng, tại mỗi vị trí, tìm phần tử nhỏ nhất tính từ vị trí đó đến cuối mảng và tráo đổi.
   Bất biến: Khi duyệt đến vị trí bên trái i.
             Các vị trí bên trái $i$ đã được sắp xếp
             Các vị trí bên phải $i$ không nhỏ hơn các vị trí bên trái i
   Khi duyệt đến vị trí i, tìm vị trí a[min] tỏng day còn lại trừ các phần tử đã sắp xếp trước đó và tráo đổi a[i] với a[min]
tạo ra 2 vỏng for lồng nhau
   vòng 2 vòng for(j): có chức năng tìm giá trị min trong mảng cần lặp
   vòng 1 vòng for(i): có nhiệm vụ giới hạn phần tử cần sắp xếp để vòng 2 chạy

*/

void selectionSort(int a[], int n)
{
    int min;
    for (int i = 0; i < n; i++)
    {
        min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[min])
                min = j;
        }
        if (min != i)
            swap(a[i], a[min]);
    }
}

int main()
{

    int a[1000];
    cout<<"enter n: ";
    int n;
    cin >> n;

    makeArray(a, n);

    selectionSort(a, n);
    printArray(a, n);
    return 0;
}