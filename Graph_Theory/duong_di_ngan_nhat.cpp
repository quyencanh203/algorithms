#include<bits/stdc++.h>
using namespace std;

int numOfPlaces;// bien luu so dia diem.
int pathNum;// bien luu so dung di .
int s,t;// la hai bien luu hai dia diem can tim duong di ngan nhat.

bool visited[1001];
int weight[1001][1001]; // mang luu trong so hay do dai cua duong di.
vector<int> adj[1001]; // mang luu dau vao la ds canh hay so duong di.
//mang nhap dau vao.
void Input() 
{
    for(int i = 0; i <pathNum; i++) 
    {
        int x,y; cin>>x>>y;// bien nhap dai diem dau va cuoi duong di.
        int w; cin>>w;// bien luu do dai duong di .
        adj[x].push_back(y);
        adj[y].push_back(x);
        weight[x][y] = weight[y][x] = w;
    }
    memset(visited,false,sizeof(visited));
}
// thuat toan dfs.
void dfs(int u)
{
    visited[u] = true;
    
    for(int v : adj[u])
    {
        if(adj[u]!=true)
        {
            dfs(v);
        }
    }
}

// mang tim duong di s_t.
void path()
{
    dfs(s);
}


int main() 
{
    cin>>numOfPlaces>>pathNum>>s>>t;

    return 0;
}



/*
Hệ thống giao thông trong thành phố bao gồm N
 địa điểm (đánh số từ 1
 đến N
) và M
 đường đi hai chiều nối các địa điểm.  Cho 2 địa điểm s
 và t
, bạn hãy viết chương trình tìm đường đi ngắn nhất từ s
 đến t
.

Đầu vào
Dữ liệu vào từ bàn phím gồm M+2
 dòng. Dòng đầu tiên chứa 2 số nguyên N,M
 (N≤104,M≤5×104)
. Dòng thứ 2 chứ 2 số nguyên s,t
. M
 dòng tiếp theo, mỗi dòng chứa 3 số nguyên u,v,w
, thể hiện có đường đi giữa u
 và v
 với độ dài w
 (w≤100)
. Các số nguyên trên cùng một dòng cách nhau bởi một dấu cách.

Đâu ra
In ra màn hình một dòng duy nhất chứa độ dài đường đi ngắn nhất từ s
 đến t
.

For example:

Input	Result
5 5
1 4
1 2 10
1 3 10
2 4 20
3 4 25
1 4 33
30

*/
