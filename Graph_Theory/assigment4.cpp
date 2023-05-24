#include<bits/stdc++.h>
using namespace std;
/*
cho ma tran ke in ra danh sach ke.
*/
int main() {
    int adj[100][100];
    vector<int> a[100];
    int n;
    cout<<"nhap so dinh cua do thi vo huong :";
    cin>>n;
    for(int i = 1 ; i <= n; i++){
        for(int j = 1 ; j <= n; j++) {
            cin>>adj[i][j];
        }
    }
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(adj[i][j]==1) {
                a[i].push_back(j);
                a[j].push_back(i);
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        cout<<i<<" :";
        for(auto s : a[i]) {
            cout<<s<<" ";
        }
        cout<<'\n';
    }
}