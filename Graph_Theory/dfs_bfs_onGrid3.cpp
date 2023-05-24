#include<bits/stdc++.h>
using namespace std;
// tim duong di ngan nhat cua hai diem tren luoi do thi.
int m,n,x,y,u,v;// m va n luu kich thuoc cua luoi; x va y luu toa do diem A; u va v luu toa do diem B.
int dx[] = {-1,0,0,1};
int dy[] = {0,-1,1,0};
char a[1001][1001];// mang luu luoi do thi.
int d[1001][1001];
bool visited[1001][1001];// mamg kiem tra da dc tham chua.

void bfs(int i, int j)
{
     queue <pair<int,int>> q;
     q.push({i,j});
     d[i][j]=0;
     visited[i][j] = true;
     while(!q.empty())
     {
        pair<int,int> top = q.front();
        q.pop();
        for(int k = 0; k < 4; k++)
        {
            int i1 = top.first+dx[k];
            int j1 = top.second+dy[k];
            if(a[i1][j1]!='x'&&visited[i1][j1]!=true && i1 >= 1 && j1 >= 1 && i1 <= m && j1 <= n)
            {
                visited[i1][j1] = true;
                d[i1][j1] = d[top.first][top.second] + 1;
                q.push({i1,j1});
            }
        }
     }
}


void inp()
{
    cout<<"nhap kich thuoc cua luoi do thi: \n";
    cin>>m>>n;
    memset(visited,false,sizeof(visited));
    cout<<"nhap do thi : \n";
     for(int i = 1; i <= m; i++)
     {
        for(int j = 1; j <= n; j++)
        {
            cin>>a[i][j];
            if(a[i][j] == 'A')
            {
                x = i;
                y = j;
            }
            if(a[i][j] == 'B')
            {
                u = i;
                v = j;
            }
        }
     }
}

void minPath()
{
    inp();
    bfs(x,y);
    if(visited[u][v] == true)
    {
        cout<< "ton tai duong di giua A va B voi so buoc nho nhat la : "<<d[u][v];
    }
    else
    {
        cout<< "ko ton tai duong di giua A va B";
    }
}


int main()
{
    minPath();
}
// 
//   6 6
//   Aooxoo
//   oxoooo
//   oxoooo
//   ooooxx
//   Boooxo
//   oooxxx

//   Aooxoo
//   oxoooo
//   oxoooo
//   ooooxx
//   ooooxo
//   oooxBx