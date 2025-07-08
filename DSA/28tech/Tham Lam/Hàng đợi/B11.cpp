#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    queue<int> q;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    int ans = 0, cd = 0;
    for(int i = 0; i < n; i++)
    {
        if(cd <= a[i])
        {
            ans++;
            cd += a[i];
        }
    }
    cout << ans;
}