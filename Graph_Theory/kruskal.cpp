#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct edge
{             // cau truc cua mot canh
    int u, v; // day la bien luu hai dau cua canh
    int w;    // day la bien luu trong so
};
const int maxn = 1001;
int n, m; // luu so dinh va so canh cua do thi
int parent[maxn], sz[maxn];
vector<edge> canh;
// cai thuat toan disjoiset hay unionfind
void make_set()
{
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
        sz[i] = 1;
    }
}

int find(int v)
{
    if (v == parent[v])
        return v;                       // dinh nay chua connected voi dinh nao khac
    return parent[v] = find(parent[v]); // cho cac dinh connectec vs nhau chung 1 cha
}

bool Union(int a, int b) // kiem tra connected
{
    a = find(a); // gan cho a bang parent cua dinh a
    a = find(b); // gan cho b = parent cua dinh b
    if (a == b)
        return false; // neu hai dinh co cung cha thi ko the gop vs nhau
    if (sz[a] < sz[b])
        swap(a, b);
    parent[b] = a;
    sz[a] += sz[b];
    return true;
}

void inp()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        edge e;
        cin >> e.u >> e.v >> e.w;
        canh.push_back(e);
    }
}

bool cmp(edge a, edge b)
{
    return a.w < b.w;
}

void kruskal()
{
    // tao cay khung cuc tieu rong
    vector<edge> mst;
    int d = 0;
    // sort danh sach canh theo chieu dai tang dan
    sort(canh.begin(), canh.end(), cmp);
    // buoc 3 lap
    for (int i = 0; i < m; i++)
    {
        if (mst.size() == n - 1)
            break;
        edge e = canh[i]; // chon e la canh nho nhat
        if (Union(e.u, e.v))
        {
            mst.push_back(e);
            d += e.w;
        }
        // Tra ve ket qua
        if (mst.size() != n - 1)
        {
            cout << "Do thi khong lien thong !\n";
        }
        else
        {
            cout << "MST :" << d << endl;
            for (auto it : mst)
            {
                cout << it.u << " " << it.v << " " << it.w << endl;
            }
        }
    }
}

int main()
{
    inp();
    make_set();
    kruskal();
}
/*
          (2)------5------(4)
          / |\             | \
        12  |  \           |  10
       /    |    \         |   \
     (1)    1      3       3    (6)
       \    |        \     |   /
        4   |          \   |  8
         \  |            \ | /
          (3)------2------(5)


*/