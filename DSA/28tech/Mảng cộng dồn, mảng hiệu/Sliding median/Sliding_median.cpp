#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll LINF= 1e18+5;
const int ING = 1e9;
const int MOD = 1E9+7;
const int MAX = 1e6+5;

int main() 
{
    // freopen("Test1.inp", "r", stdin);
    // freopen("Test1.out", "w", stdout);
    int n, k; cin >> n >> k;
    ll a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    multiset<int> s;
    for(int i = 0; i < k; i++) s.insert(a[i]);
    auto iter = s.begin();
    advance(iter, (k - 1) / 2);
    for(int i = k; i <= n; i++)
    {
        cout << *iter << " ";
        if(i == n) break;
        s.insert(a[i]);
        if(*iter > a[i]) iter--;
        if(a[i - k] <= *iter) iter++;
        s.erase(s.lower_bound(a[i - k]));
    }
}
