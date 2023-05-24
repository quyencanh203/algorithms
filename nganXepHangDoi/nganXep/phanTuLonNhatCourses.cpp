
#include <bits/stdc++.h>
#include <stack>

using namespace std;

void findMaxStack(stack<int> st)
{
    stack<int> st1 = st;
    int max = 0;
    while (!st1.empty())
    {
        if (max < st1.top())
        {
            max = st1.top();
        };
        st1.pop();
    }
    cout << max << endl;
}

int main()
{
    int n;
    stack<int> st;
    cin >> n;
    while (n > 0)
    {
        int a; // chi so thao tac theo de bai 1 or 2 or 3
        cin >> a;
        if (a == 1) // neu 1 thi them pt
        {
            int x;
            cin >> x;
            st.push(x);
        }
        else
        {
            if (a == 2) // neu a==2 thi xoa phan tu
            {
                st.pop();
            }
            else
            {
                findMaxStack(st);
            }
        }
		n--;
    }
}
