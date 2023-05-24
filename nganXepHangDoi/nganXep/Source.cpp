#include <bits/stdc++.h>
#include <stack>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n], b[n];
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        st.push(a[0]);

        for (int j = 1; j < st.size(); j++)
        {
            
            if (a[i] > st.top())
            {
                b[i]=st.top();
                st.pop();
            }
        }

        st.push(a[i]);
    }

    cout<<st.size();
    return 0;
}