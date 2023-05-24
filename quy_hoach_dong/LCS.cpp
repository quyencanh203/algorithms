#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s1, s2;
    cout << "enter s1 and s2 : ";
    cin >> s1 >> s2;
    int F[100][100];
    int k = 0;
    memset(F, 0, sizeof(F));
    for (int i = 1; i <= s1.size(); i++)
    {
        for (int j = 1; j <= s2.size(); j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                F[i][j] = F[i - 1][j - 1] + 1;
            }
            else
            {
                F[i][j] = max(F[i - 1][j], F[i][j - 1]);
            };
            k = max(k, F[i][j]);
        }
    }
    cout << k;
    return 0;
}
/*
tim do dai chuoi chung dai nhat.
vd: batman
    banana
    => 4
*/