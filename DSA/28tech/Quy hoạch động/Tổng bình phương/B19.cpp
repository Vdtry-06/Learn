#include<bits/stdc++.h>
using namespace std;
const int MAX = 1e6 + 5;
int f[MAX];
int n;
int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        f[i] = i;
        for(int j = 1; j <= sqrt(i); j++)
        {
            f[i] = min(f[i] , f[i - j * j] + 1);
        }
    }
    cout << f[n];
}