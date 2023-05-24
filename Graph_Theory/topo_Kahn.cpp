#include<bits/stdc++.h>
using namespace std;

int n,m; // so dinh va so canh cua do thi

vector<int> adj[1001]; // mang dau vao
bool visited[1001];
vector<int> topo;// mang luu sx topo
int in[1001]; // mang tinh ban bac vao

void inp()
{
    cout<<"nhap so dinh va so canh cua cay do thi: \n";
    cin>>n>>m;
    memset(visited,false,sizeof(visited));
    memset(in,0,sizeof(in));
    cout<<"nhap cay do thi co huong : \n";
    for(int i = 1; i <= m; i++)
    {
        // vi de co sx topo thi do thi phai la do thi co huong
        int x,y; cin>>x>>y;// voi y chi huong di cua vector
        adj[x].push_back(y); 
        in[y]++;// tinh ban bac vao ban dau 
    }
}

// thuat toan xoa dan dinh kahn.
void kahn()
{
    queue<int> q;
    for(int i = 1; i <= n; i++)
    {
        if(in[i]==0)
        {
            q.push(i);
        }
    }
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        topo.push_back(u);
        for(int v : adj[u])
        {
            in[v]--;
            if(in[v]==0)
            {
                q.push(v);
            }
        }
    }
    cout<<"sx topo theo thuat toan Kahn la: \n";
    for(int x : topo)
    {
        cout<<x<<" ";
    }
}

int main()
{
    inp();
    kahn();
    return 0;
}
/*
7 7

1 2
2 3
2 4
3 5
4 5
1 6
7 6
*/