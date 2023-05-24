#include <bits/stdc++.h>
#include <queue>
using namespace std;

void makeQueue(queue<int> &q, int n, int &sum)  // nhap gia tri vao queue luu y truyen tham chieu cho queue
{
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        q.push(x);
        sum += x;
    }
}

int equalSum(int &sum1, queue<int> &q1, int &sum2, queue<int> &q2, int &sum3, queue<int> &q3)
{
    while (sum1 != sum2 || sum1 != sum3 || sum2 != sum3) // neu tong khong bang nhau thuc hien vong while
    {
        if (sum2 >= sum1 && sum2 > sum3) // y tuong: tim tong max trong 3 tong cua 3 day roi tru di phan tu front cua queue
        {                                //          cu the cho den khi het vong lap
            sum2 -= q2.front();
            q2.pop();
        }
        else
        {
            if (sum1 >= sum3 && sum1 > sum2)
            {
                sum1 -= q1.front();
                q1.pop();
            }
            else
            {
                if (sum3 >= sum2 && sum3 > sum1)
                {
                    sum3 -= q3.front();
                    q3.pop();
                }
            }
        }
    }
    return sum1;
}

int main()
{
    queue<int> q1;
    queue<int> q2;
    queue<int> q3;
    int n1, n2, n3;
    int sum1 = 0, sum2 = 0, sum3 = 0;
    cin >> n1 >> n2 >> n3;
    makeQueue(q1, n1, sum1);
    makeQueue(q2, n2, sum2);
    makeQueue(q3, n3, sum3);

    cout << equalSum(sum1, q1, sum2, q2, sum3, q3);

    return 0;
}
