#include <bits/stdc++.h>
using namespace std;

int n, m;              // n la so dinh, m la so canh.
vector<int> adj[1001]; // mang luu do thi dau vao.
bool visited[1001];
vector<int> topo; // xap xep topo.

void input()
{
    cout << "nhap so dinh va so canh trong do thi: \n";
    cin >> n >> m;
    cout << "nhap danh sach canh cua do thi co huong : \n";
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
    }
    memset(visited, false, sizeof(visited));
}

void dfs(int u)
{
    visited[u] = true;
    for (int x : adj[u])
    {
        if (visited[x] != true)
        {
            dfs(x);
        }
    }
    topo.push_back(u); // dua vao day topo
}

void output()
{
    input();
    for (int i = 1; i <= n; i++) // duyet cac dinh cua do thi
    {
        if (visited[i] != true)
        {
            dfs(i);
        }
    }
    reverse(topo.begin(), topo.end()); // dua ve thu tu dung cua sap xep topo
    for (int x : topo)
    {
        cout << x << " ";
    }
}

int main()
{
    output();
}
/*
        (1)--->(2)--->(3)
         |      |      |
         V      v      v
 (7)--->(6)    (4)--->(5)

 sap xep topo tim dc la: 7 1 6 2 4 3 5
*/