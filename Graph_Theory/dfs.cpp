#include<bits/stdc++.h>
using namespace std;

class Graph {
    public: 
        int M ; // so canh
        bool visited[100];
        vector<int> adj[100];
        
        void ADJ();
        void dfs(int v);
};

void Graph::ADJ()
{
    for(int i = 1; i <= M; i++)
    {
        int x, y; cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
}

void Graph::dfs(int v)
{
    visited[v] = true;
    cout<<v<<" ";
    for(int u: adj[v])
    {
        if(visited[u] != true) dfs(u);
    }
}

int main()
{
    Graph g;
    memset(g.visited,false,sizeof(g.visited));
    cout<<"nhap so canh \n";
    cin>>g.M;
    cout<<"nhap ds ke\n";
    g.ADJ();
    cout<<"day la ds duyet dfs(2)\n";
    g.dfs(2);
    return 0;
}