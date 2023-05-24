#include <bits/stdc++.h>
using namespace std;
// tim duong di ko co trong so.
/*
input: nhap so dinh va so canh cua do thi.
     : nhap ds ke(adjacency list)
     : nhap hai dinh s va t
output : in ra duong di tu s den t neu co
*/
int edge, top, s, t;
bool visited[1000];    // mang de xac nhan dinh da duoc tham hay chua.
vector<int> adj[1000]; // mang luu tru danh sach ke.
int parent[1000];      // mang luu cha cua dinh duoc duyet.

// ham nhap ds ke vo huong.
void enterAdj()
{
    for (int i = 1; i <= edge; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
}

// ham nhap ds ke co huong.
void enterAdj2()
{
    for (int i = 1; i <= edge; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
    }
}

// thuat toan dfs.
void dfs(int u)
{
    visited[u] = true;   // danh dau la dinh da duoc tham.
    for (int v : adj[u]) // duyet cac dinh ke cua u;
    {
        // duyet theo chieu sau dfs bang de quy.
        if (visited[v] != true) // kiem tra dinh v co duoc tham hay ko.
        {
            parent[v] = u; // ghi nhan parent cua v la u.
            dfs(v);        // de quy ve dinh v.
        }
    }
}

// thuat toan bfs.
void bfs(int x)
{
    queue<int> q;      // tao hang doi uu tien de luu cac dinh trong do thi khi duyet qua.
    visited[x] = true; // danh dau dinh u da duoc tham.
    q.push(x);         // them dinh vua duoc tham vao hang doi uu tien.
    while (!q.empty()) // neu hang doi uu tien q ko rong.
    {
        // dung vong while va vong for de duyet do thi theo chieu rong dfs.
        int u = q.front();        // bien u luu phan tu tai dau hang doi uu tien hien tai.
        q.pop();                  // xoa phan tu q.front ra khoi hang doi uu tien.
        for (int v : adj[u])      // duyet cac dinh de voi dinh u.
        {
            if (visited[v] != true) // kiem tra xem dinh de cua u da duoc tham hay chua.
            {
                visited[v] = true; // danh dau da duoc tham.
                parent[v] = u;
                q.push(v);         // them vao hang doi
            }
        } // ket thuc vong for. moi mot vong for duyet cac dinh de thi se in ra mot dinh da duyet va xoa dinh dau q ra khoi hang doi.
    }
}

// ham tim duong di s den t.
void path()
{
    memset(visited, false, top); // khoi tao cac dinh chua duoc tham la false.
    memset(parent, 0, top);      // cac dinh chua duoc tham thi ko co cha tuc la 0.
    bfs(s);                      // goi dfs hoac bfs den dinh dau de tim duong di den t.
                                 // bfs va dfs se cho duong di khac nhau. 
    if (visited[t] == false)     // kiem tra dinh t co duoc tham hay ko.
    {
        cout << "ko ton tai duong di tu s-t\n";
    }
    else
    {
        // truy vet duong di s-t.
        vector<int> path; // cac vector se luu duong di s-t;
        while (t != s)    // dung vong while de truy vet nguoc tu t ve s.
        {
            path.push_back(t); // them t vao cac vector path luu duong di.
            t = parent[t];
        }
        path.push_back(s);
        reverse(path.begin(), path.end()); // dao nguoc thu tu luu cac phan tu trong path cho dung thu du duyet duong di.
        // in ra duong di s-t.
        cout << "duong di s-t la:\n";
        for (int x : path)
        {
            cout << x << " ";
        }
    }
}

int main()
{
    cout << "nhap lan luot so luong dinh va canh:\n";
    cin >> top >> edge;
    cout<<"nhap danh sach ke cua do thi:\n";
    enterAdj2(); // nhap danh sach ke.
    cout << "nhap dinh s va t:\n";
    cin >> s >> t;
    path();
    return 0;
}
/* ds ke vo huong
10 8

1 2
2 3
2 4
3 6
3 7
6 7
5 8
8 9
*/


/* ds ke co huong.
10 10

1 2
2 3
2 4
3 6
3 7
6 7
7 5
5 8
5 10
8 9

1 10
dung dfs=> 1 2 3 6 7 5 10.
1 8
dung bfs=> 1 2 3 7 5 8
*/