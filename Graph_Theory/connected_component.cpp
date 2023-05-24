#include <bits/stdc++.h>
/*
dem so thanh phan lien thong tren do thi vo huong.
input: nhap so luong dinh va so luong canh la n va m .
       1 mang luu danh sach ke
output: so thanh phan lien thong.
*/
using namespace std;
int edge, top;         // bien luu so luong canh va so dinh cua do thi.
bool visited[1000];    // mang xac dinh xem cac dinh da duoc tham hay chua.
vector<int> adj[1000]; // adj : adjacency list
// mang nhap danh sach ke.
void enterAdj()
{
    memset(visited, false, top); // khoi tao cac dinh ve gia tri chua tham la false.
    for (int i = 1; i <= edge; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
}

// duyet theo chieu sau.
void dfs(int u) // u la dinh can duyet cua do thi.
{
    visited[u] = true; // danh dau da duoc tham.
    cout << u << " ";  // in ra thu tu duyet .
    for (int v : adj[u])
    { // duyet cac dinh ke.
        if (visited[v] != true)
            dfs(v); // neu chua duoc tham thi goi de quy dfs den dinh do.
    }
}

// duyet theo chieu rong.
void bfs(int x) 
{
    queue <int> q;
    visited[x] = true; // danh dau dinh da duoc tham.
    q.push(x); // dua dinh moi duoc va hang doi uu tien.

    while(!q.empty())
    {
        int u = q.front(); // bien u luu phan tu dau hang doi hien thoi.
        cout<<u<<" ";// in ra thu tu duyet.
        q.pop();// sau khi in ra thi xoa khoi hang doi.
        for(int v : adj[u]) // duyet cac dinh ke voi dinh u theo chieu rong.
        {
            if(visited[v]!=true)// kiem tra dinh da duoc tham hay chua. 
            {
                visited[v] = true;// danh dau da duoc tham.
                q.push(v);// cho dinh vao hang doi uu tien.
            }
        }// ket thuc vong for tiep tuc duyet vong while.
    }
}

// ham duyet thanh phan lien thong.
void connectedComponent()
{
    int ans = 0;
    for (int i = 1; i <= top; i++)
    {
        if (visited[i] != true)
        {
            cout << "\n cac dinh thuoc thanh phan lien thong thu " << ++ans << "la: \n";
                bfs(i);// co the dung dfs hoac dfs .
        }
    }
    cout<<"\n so thanh phan lien thong la: "<<ans<<"\n";
    if(ans > 1) cout<<"\n do thi nay ko lien thong";
    else cout<<"\n do thi lien thong";
}

int main()
{
    cout<<"nhap lan luot so dinh va so canh ";
    cin>>top>>edge;
    enterAdj();   // thuc hien nhap ds ke (adjacency)
    connectedComponent();
    return 0;
}
/*
nhap lan luot so dinh va so canh 10 8
1 2
2 3
2 4
3 6
3 7
6 7
5 8
8 9
*/