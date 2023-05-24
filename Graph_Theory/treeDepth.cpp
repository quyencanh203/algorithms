#include <bits/stdc++.h>
using namespace std;

vector<int> edgeList[1000]; // danh sách kề
bool visited[1000]; // đánh dấu các đỉnh đã được duyệt qua
int maxHeight = 0; // chiều cao của cây

void DFS(int u, int depth)
{
    visited[u] = true; // đánh dấu đỉnh u đã được duyệt qua
    maxHeight = max(maxHeight, depth); // cập nhật chiều cao của cây

    // Duyệt qua các đỉnh kề của đỉnh u
    for (int v : edgeList[u])
    {
        if (!visited[v])
        {
            DFS(v, depth + 1); // tiếp tục duyệt đỉnh kề v với độ sâu là depth + 1
        }
    }
}

int main()
{
    int n;
    cin >> n; // số đỉnh của cây

    // Nhập danh sách kề của cây
    for (int i = 0; i < n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        edgeList[x].push_back(y);
        edgeList[y].push_back(x);
    }

    // Gọi DFS với đỉnh gốc là 0 và độ sâu là 0
    DFS(0, 0);

    cout << maxHeight << endl; // in ra chiều cao của cây
    
    return 0;
}

