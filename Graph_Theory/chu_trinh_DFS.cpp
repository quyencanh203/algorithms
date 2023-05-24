#include <bits/stdc++.h>
using namespace std;

int n, m, st, en;      // la so dinh va so canh cua do thi, st va en luu diem dau va cuoi cua chu trinh
vector<int> adj[1001]; // luu do thi
bool visited[1001];    // danh dau da dc tham hay chua
int parent[1001];      // mang luu cha cua dinh duoc duyet qua

void inp()
{
    cout << "nhap so dinh va so canh cua do thi: \n";
    cin >> n >> m;
    memset(visited, false, sizeof(visited));
    cout << "nhap do thi :\n";
    for (int i = 1; i <= n; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
}

bool dfs(int u) // u la lu dinh dang duyet
{
    visited[u] = true;
    for (int v : adj[u])
    {
        if (visited[v] != true)
        {
            parent[v] = u;
            if (dfs(v) == true) // neu dfs(v,u) co chu trinh return true
                return true;
        }
        else
        {
            if (v != parent[u])
            {
                st = v;
                en = u;
                return true; // tuc u-v la canh nguoc
            }
        }
    }
    return false; // duyet qua khong co chu trinh return false
}

void outp()
{
    vector<int> process; // luu chu trinh trong do thi
    inp();
    for (int i = 1; i <= n; i++) // dung vong for duyet de khi do thi co nhieu thanh phan lien thong van duyet duoc
    {
        if (visited[i] != true)
        {
            if (dfs(i) == true)
            {
                process.push_back(st);
                while(en!=st)
                { 
                    process.push_back(en);
                    en = parent[en];// truy nguoc cac dinh duoc duyet qua de luu vao chu trinh
                }
                process.push_back(st);
                reverse(process.begin(),process.end());// lat lai chu trinh cho dung thu tu duyet
                cout << "yes\n";
                cout<<"chu trinh do la:\n";
                for(int x : process)
                {
                    cout<<x<<" ";
                }
                return;
            }
        }
    }
    cout << "no";
}
int main()
{
    outp();// chi xet duoc mot chu trinh ton tai trong do thi.
    return 0;
}