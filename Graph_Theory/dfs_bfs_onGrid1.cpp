#include <bits/stdc++.h>
using namespace std;
// bai1: dem so thanh phan lien thong tren luoi.
int m, n;                 // cac bien luu chieu dai va chieu rong cua luoi do thi.
char a[1001][1001];       // mang danh dau cac ki tu trong luoi.
bool visited[1001][1001]; // mang xac nhan la dinh da dc tham chua.

// mang luu toa do huong di chuyen.
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

// dfs .
void dfs(int i, int j) // i va j luu toa do cua ki tu tren luoi.
{
    visited[i][j] = true;
    cout << i << " " << j << '\n';
    // duyet cac dinh lien ke.
    for (int k = 0; k < 4; k++)
    {
        int i1 = i + dx[k];
        int j1 = j + dy[k];
        // kiem tra xem cac o ke co du dieu kien di chuyen ko.
        if (i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= m && a[i1][j1] == 'x' && visited[i1][j1] != true)
        {
            dfs(i1, j1); // duyet theo chieu sau bang cach goi de quy .
        }
    }
}

// bfs.
void bfs(int i, int j)
{
    queue<pair<int, int>> q;
    visited[i][j] = true; // danh dau la da duoc tham.
    q.push({i, j});       // them dinh cua luoi do thi vao hang doi.

    while (!q.empty())
    {
        pair<int, int> top = q.front();
        q.pop();
        // duyet cac dinh ke trong luoi do thi.
        for (int k = 0; k < 4; k++)
        {
            int i1 = top.first + dx[k];
            int j1 = top.second + dy[k];
            if (i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= m && a[i1][j1] == 'x' && visited[i1][j1] != true)
            {
                cout << i1 << " " << j1 << '\n';
                visited[i1][j1] = true;
                q.push({i1, j1});
            }
        }
    }
}

// ham kiem tra thanh phan lien thong.
void connectComponent()
{
    int count = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i][j] == 'x' && visited[i][j] != true)
            {
                cout << "thu tu duyet cua thanh phan lien thong thu" << ++count << "la:\n";
                bfs(i, j);
            }
        }
    }
    cout << "so thanh phan lien thong cua luoi do thi la: \n"
         << count;
}

// ham nhap dau vao.
void inp()
{
    cout << "nhap m va n :\n";
    cin >> m >> n;
    memset(visited, false, sizeof(visited));
    cout << "nhap luoi do thi:\n";
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j]; // nhap cac ky tu ao luoi do thi.
        }
    }
}

int main()
{
    inp();
    connectComponent();
    return 0;
}
/*
6 6
xxxooo
ooxooo
oxxxxo
ooooox
xxoxox
xoxxox
*/