#include <bits/stdc++.h>
#include <stack>

using namespace std;

void check(string s)
{
    int len = s.length();
    stack<char> st;

    for (int i = 0; i < len; i++)
    {
        if (s[0] == '}' || s[0] == ')' || s[0] == '}')
        {
            cout << "no"<<endl;
            return;
        }
        if (s[i] == '{' || s[i] == '(' || s[i] == '[')
        {
            st.push(s[i]); // neu pt thoa man dieu kien thi se push vao stack
        }
        else
        {
            if (s[i] == '}' && st.top() == '{')
            {
                st.pop(); // neu pt ma tm phan tu tai dinh stack thi xoa di
            }
            else
            {
                if (s[i] == ')' && st.top() == '(')
                {
                    st.pop(); // neu pt ma tm phan tu tai dinh stack thi xoa di
                }
                else
                {
                    if (s[i] == ']' && st.top() == '[')
                    {
                        st.pop(); // neu pt ma tm phan tu tai dinh stack thi xoa di
                    }
                }
            }
        }
    }
    if (st.empty())
        cout << "yes"<<endl;
    else
        cout << "no"<<endl;
}

int main()
{
    string s;
    int n;
    cin >> n;
    while (n--)
    {
        cin >> s;
        check(s);
    }
    return 0;
}