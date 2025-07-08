#include<bits/stdc++.h>
#define pr pair<int, int>
#define ll long long
#define fi first
#define se second
using namespace std;
const int MAX = 1e6 + 5;
pr a[MAX];
int n;

bool cmp(pr a, pr b)
{
    return a.se < b.se;
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i].fi >> a[i].se;
    }
    sort(a, a + n, cmp);
    int cnt = 1, tmp = a[0].se;
    for(int i = 0; i < n; i++)
    {
        if(a[i].fi > tmp)
        {
            cnt++;
            tmp = a[i].se;
        }
    }
    cout << cnt;
}