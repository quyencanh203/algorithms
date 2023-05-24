#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {    
    cout<<"nhap so dinh va so canh: ";
     int m, n;
     cin>>n>>m;
     int a[100][100];
    for(int i = 0; i < m ; i++) {
        int u, v;
        cin>>u>>v;
        a[u][v] = a[v][u] = 1;
    }

    cout<<"ma tran ke tuong ung cua do thi la: \n";
    for(int i = 1 ; i <= n; i++) {
        cout<<endl;
        for(int j = 1 ; j <= n; j++) {
            cout<<a[i][j]<<" ";
        }
    }
    return 0;
}
/*
 *dòng đầu tiên chứa 2 số m và n là số đỉnh và số cạnh 
 M dòng tiếp theo mỗi dòng chứa 2 số nguyên u,v biểu diễn cạnh u và v của đồ thị
 các cạnh được liệt kê theo thứ tự tăng dần của các đỉnh 
 Output
 in ra ma tran ke tương ứng của đồ thị  
*/