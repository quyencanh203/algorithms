#include <bits/stdc++.h>
#include <stack>

using namespace std;

void makeStack(int a, stack<int> &st) // nhap gia tri vao ngan xep
{
    int s[100];
    for (int i = 0; i < a; i++)
    {
        cin >> s[i];
    }
    for (int i = a - 1; i >= 0; i--)
    {
        st.push(s[i]);
    }
}

int takeScores(stack<int> &st1, stack<int> &st2, int x)
{
    int sum = 0;
    int scores = 0;
    while (sum <= x)        // y tuong de scores max la compare 2 phan tu cai nao min thi cong vao sum va scores ++
    {
        if (st1.empty() && st2.empty()) // neu cac phan tu trong 2 stack == empty thi tra ve scores
            return scores;
        if (!st1.empty() && !st2.empty()) // neu ca 2 stack ko trong thi tiep tuc
        {
            if (st1.top() < st2.top())
            {
                sum += st1.top();
                st1.pop();
            }
            else
            {
                sum += st2.top();
                st2.pop();
            }
            scores++;
        }
        else        // neu 1 trong 2 stack == emppty thi thuc hien cho stack con lai
        {
            if (!st1.empty())
            {
                sum += st1.top();
                st1.pop();
                if(st1.empty()) return scores; 
            }
            else
            {
                sum += st2.top();
                st2.pop();
                if(st2.empty()) return scores;
            }
        }
    }

    return scores;
}

int main()
{
    stack<int> st1;
    stack<int> st2;
    int m, n, x;
    cin >> m >> n >> x;
    makeStack(m, st1);
    makeStack(n, st2);
    cout << takeScores(st1, st2, x);
}