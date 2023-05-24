#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int n, m, s;// luu so dinh va so canh cua do thi, s dinh can tim duong di 
const int maxn = 100001;
vector<pair<int,int>> adj[maxn]; // luu ds ke cua do thi can tim kiem duong di ngan nhat den cac dinh

void nhap()
{
    cin>>n >>m >>s;
    for(int i = 0; i < m; i++)
    {
        int x, y, w;// bien luu hai dau duong di va trong so(weight)
        cin>>x>>y>>w;
        adj[x].push_back({y,w});
    }
}

const int INF = 1e9;
void dijkstra(int s)
{
    // mang luu khoang cach duong di
    vector<ll> d;
    d[s] = 0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> Q;
    // khoang cach, dinh
    Q.push({0,s});
    while(!Q.empty())
    {
        // chon ra dinh co khoang cach tu s nho nhat
        pair<int,int> top = Q.top(); Q.pop();
        int u = top.second; // dinh
        int kc = top.first; // khoang cach
        if(kc > d[u]) continue;
        // relaxtion : thong qua dinh u da biet khoang cach ngan nhat tinh tu S, 
        // cap nhap khoang cach voi cac dinh ke voi u
        for(auto it : adj[u])
        {
            int v = it.first;
            int w = it.second;
            if(d[v]>d[u]+w)
            {
                d[v] = d[u]+w;
                Q.push({d[v],v});
            }
        }
    }
    for(int i = 1; i <= n; i++)
    {
        cout<<d[i]<<" ";
    }
}

int main()
{
    nhap();
    dijkstra(s);
    return 0;
}