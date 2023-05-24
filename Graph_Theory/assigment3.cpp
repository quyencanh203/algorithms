/*
cho ma tran ke in ra ds canh canh.
*/
#include<bits/stdc++.h>
using namespace std;

int main() {
    vector<pair<int,int>> edge;
    int adj[100][100];
    int n;
    cout<<"nhap so dinh ma tran ke: ";
    cin>>n;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n ;j++) {
            cin>>adj[i][j];
        }
    }

for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n ;j++) {
            if(adj[i][j] == 1 && i < j) {
                edge.push_back({i,j});
            }
        }
    }

    cout<<"danh sach canh tuong ung la: \n";
    for(auto k : edge) {
        cout<<k.first<<" "<<k.second<<endl;
    }
    return 0;
}