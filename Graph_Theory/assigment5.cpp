/*
cho danh sach ke in ra ma tran ke.
*/
#include<bits/stdc++.h>
using namespace std;

int main() {
    vector<int> adj[100];
    int a[100][100];
    int n;
    cout<<"nhap so canh cua do thi vo huong:";
    cin>>n;
    cin.ignore();
    for(int i = 1; i <= n; i++) {
        string s,num;
        getline(cin,s);
        stringstream ss(s);
        while(ss >> num) {
            a[i][stoi(num)] = 1;
        }
    }
    return 0;
}