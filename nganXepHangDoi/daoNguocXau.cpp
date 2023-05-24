#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        string a, b;
        cin >> a >> b;
        int len=a.length();
        for (int i = 0; i < len; i++)
        {
            if ('a' <= a[i] && a[i] <= 'z')
            {
            a[i] -= 32;
            }
        }

        if (a.find(b) <= len)
            cout << "YES";
        else
            cout << "NO";
        }

    return 0;
}