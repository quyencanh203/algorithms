#include <bits/stdc++.h>
using namespace std;
/*
bai2: co luoi do thi tim duong di giua hai diem tren luoi.
     Aooxoo
     oxoooo
     oxoooo
     ooooxx
     Boooxo
     oooxxx

     o: la co duong di , x la khon co duong di.
     A B la hai diem can kiem duong di.
*/

int m, n, x, y, p, q;     // m,n la kich thuoc cua luoi do thi; x,y la toa do cua A; p, q luu toa do cua diem B.
char a[1001][1001];       // mang luu cac ki tu trong luoi do thi.
bool visited[1001][1001]; // mang danh dau da duoc duyet hay chua.

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};
// dfs
void dfs(int i, int j)
{
    visited[i][j] = true;        // danh dau da duoc tham;
    for (int k = 0; k <= 3; k++) // duyet cac dinh ke ma co duong di hay cac o lien ke.
    {
        int i1 = i + dx[k];
        int j1 = j + dy[k];
        if (i1 <= n && i1 >= 1 && j1 <= m && j1 >= 1 && a[i1][j1] != 'x' && visited[i1][j1] != true) // dieu kien de i1j1 luon nam trong luoi do thi
        {
            dfs(i1, j1); // de quy de duyet theo chieu sau dfs.
        }
    }
}
// bfs.
void bfs(int i, int j)
{ 
    //vector<pair<int,int>> path;
    queue<pair<int,int>> que;// tao hang doi de luu cac dinh da di qua.
    visited[i][j] = true; // danh dau la dinh da duoc duyet.
    que.push({i,j});// sau khi danh dau cho vao hang doi uu tien.
    while(!que.empty()) // dung vong while de thuc hien qua trinh duyet va in 
    {
        pair<int,int> top;
        top = que.front();
        que.pop();
        for(int k = 0; k < 4; k++) // duyet cac dinh lien ke hay cac o lien ke
        {
            int i1 = top.first + dx[k];
            int j1 = top.second + dy[k];
            if(a[i1][j1]!='x'&&visited[i1][j1]!=true && i1 >= 1 && j1 >= 1 && i1 <= m && j1 <= n)
            {
                visited[i1][j1] = true;
                que.push({i1,j1});
            }
        }
    }
}

// input.
void input()
{
    cout << "nhap kich thuoc cua luoi do thi m va n: \n";
    cin >> m >> n;
    cout << "nhap luoi do thi:\n";
    memset(visited, false, sizeof(visited));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
            if (a[i][j] == 'A')
            {
                x = i;
                y = j;
            }
            if (a[i][j] == 'B')
            {
                p = i;
                q = j;
            }
        }
    }
}

int main()
{
    input();
    //dfs(x, y);
    bfs(x,y);
    if (a[p][q] == 'B' && visited[p][q] == true)
    {
        cout << "co duong di AB" << '\n';
        cout << "A: " << x << " " << y << '\n';
        cout << "B: " << p << " " << q << '\n';
    }
    else
    {
        cout << "A va B khong co duong di";
    }
    return 0;
}
// /*
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
