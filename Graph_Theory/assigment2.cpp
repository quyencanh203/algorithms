#include<bits/stdc++.h>
using namespace std;

int main() {

    int n, m;
    cout<<"nhap so dinh va so canh :";
    cin>>n>>m;
    vector<int> adj[100];
    for(int i = 0; i < m; i++) {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    cout<<"danh sach ke tuong ung la: \n";
    for(int i = 1; i <= n; i++) {
        cout<<i<<":";
        for(int j : adj[i]) {
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}
/*
cho danh sach canh chuyen sang danh sach ke
*/