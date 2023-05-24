#include <bits/stdc++.h>
using namespace std;
/*
nhap so canh N.
nhap ds canh.
in ra thu tu duyet bfs.
*/
int n;
vector<int> edgeList[100];// tao 100 phan tu kieu vector de luu danh sach canh.
queue<int> q; // tao hang doi uu tien de luu cac phan tu duoc duyet.
bool visited[100]; // tao mang visited de danh dau la da duyet hay chua.

void enterEdgeList() // nhap danh sach canh .
{
    for (int i = 0; i < n; i++)
    {
        int x;
        int y;
        cin >> x;
        cin >> y;
        edgeList[x].push_back(y);
        edgeList[y].push_back(x);
    }
    memset(visited, false, sizeof(visited));// cho cach gia tri cua mang visited = false
}

void BFS(int u) 
{
    visited[u] = true; // duyet qua dinh u.
    q.push(u);// cho u vao hang doi uu tien q.
    while (!q.empty()) // neu trong queue ko rong thi thuc hien .
    {
        int v = q.front(); // cho bien v luu phan tu tai dinh queue.
        q.pop(); // xoa phan tu duoc v luu gia tri.
        cout<<v<<" ";// in ra thu tu duyet.
        for (int x : edgeList[v])// dung vong for duyet qua cac canh chung dinh v.
        {
            if (visited[x]!=true)// hoac ! visited[x] 
            {
                q.push(x); 
                visited[x] = true;
            }
        }
    }
}

int main()
{
    cin>>n;
    enterEdgeList();
    BFS(1);
    return 0;
}
// 11 
// 1 2
// 1 3
// 1 5
// 1 10
// 2 4
// 3 6
// 3 7
// 3 9
// 6 7
// 5 8
// 8 9
// 1 2 3 5 10 4 6 7 9 8 
