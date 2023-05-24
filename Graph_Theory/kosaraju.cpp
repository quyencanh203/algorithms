// kasaraju thanh phan lien thong manh
#include <bits/stdc++.h>
using namespace std;
// buoc1: goi dfs() tren do thi ban dau, luu thu tu duyet cac dinh vao 1 stack.
// buoc2: xay duong do thi voi vec to giua hai dinh lat nguoc: transpose gragh
// buoc3: lan luot pop cac dinh trong stack o buoc1 va goi thuat toan dfs() liet ke cac thanh phan lien thong manh
// lien thong manh(trongly connected components): ky hieu SCC.
// phuc tap thuat toan dfs() : O(V+E) suyra kasaraju O(2(V+N)).

int n, m;                           // the variable saves the number of top and the number of edge.
vector<int> adj[1001], r_adj[1001]; // vector saves order adj of G and TG.
bool used[1001];                    // the array making the tops visited.
stack<int> st;                      // stack saves order of going dfs().

/*
   (1)------>(2)                     ( 7)
    ^         |                     ^    \
    |         v                    /      v
   (4)<------(3)------>(5)------>(6)<-----(8)  this is H1 G
   (1)<------(2)                     ( 7)
    |         ^                     /    ^
    v         |                    v      \
   (4)------>(3)<------(5)<------(6)----->(8)  this is H1 TG
   inp();
   scc():
         dfs1(1)-> 1 2 3 4 5 6 7 8 
         stack -> 4 8 7 6 5 3 2 1
         dfs2(1) -> 1 4 3 2 .count =1;
         dfs2(5) -> 5       .count =2;
         dfs2(6) -> 6 8 7   .count =3;
         stack = empty -> ket thuc.

*/
void inp()
{
    cin >> n >> m; // enter the top and the edge in the directed graph.
    int x, y;
    for (int i = 1; i <= n; i++) // algorithmic complexity O(n)
    {
        cin >> x >> y;         // enter two the index of the directed edge.
        adj[x].push_back(y);   // this is adj of graph in H1.
        r_adj[y].push_back(x); // this is r_adj of transpose graph in H1
    }
}

void dfs1(int u) // dfs1 is used for the G graph.
{
    used[u] = true; // the top is visited by dfs().
    cout<<u<<" ";
    st.push(u);     // the top u is pushed in the stack.
    for (int v : adj[u])
    {
        if (used[v] != true)
        {
            dfs(v); // call recursive to the top v.
        }
    }
}
void dfs2(int u) // dfs1 is used for the TG graph.
{
    used[u] = true; // the top is visited by dfs().
    for (int v : r_adj[u])
    {
        if (used[v] != true)
        {
            dfs2(v); // call recursive to the top v.
        }
    }
}

void SCC()// strongly connected compoment.
{
    memset(used,false,sizeof(used));
    int count = 0;
    // b1: call dfs() for the first graph.
    for(int i = 1; i <= n; i++) // the loop is used to make sure to go visited all the vertices.
    {
        if(used[i] != true)
        {
            dfs1[i];
        }
    }
    cout<<endl;
    memset(used,false,sizeof(used));
    while(!st.empty()) // if the tack is not emptied 
    {
        int u = st.top();
        st.pop(); // the vetices is deleted in the stack.
        if(used[u]!=true)
        {
            dfs2[u];
            count++;
            cout<<endl;
        }
    }
}
int main()
{
    intp();
    SCC();
    return 0;
}