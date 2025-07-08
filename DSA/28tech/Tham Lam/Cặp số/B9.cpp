#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAX = 1e6 + 7;
ll n, a[MAX], d1 = 0, d2 = 0, cnt = 0;
int main()
{
    cin >> n;
    for(int i = 0;i < n; i++) 
    {
        cin >> a[i];
        if(a[i] % 2 == 0) d1++;
        else d2++;
    }
    if(n % 2 != 0)
    {
        cout << "NO";
        return 0;
    }
    sort(a, a + n);
    for(int i = 1; i < n; i++)
    {
        if(abs(a[i] - a[i - 1]) == 1) cnt++;
    }
    if(d1 % 2 == 0 && d2 % 2 == 0) cout << "YES";
    else if(cnt > 0 && d1 % 2 != 0 && d2 % 2 != 0) cout << "YES";
    else cout << "NO";
}
