#include<bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using ll = long long;
#define file() freopen("Test1.inp", "r", stdin); freopen("Test1.out", "w", stdout);
#define faster() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pq_min priority_queue<ll, vector<ll>, greater<ll>> 
#define pq_max priority_queue<int> 
#define FORD(i, r, l) for(int i = r; i >= l; i--)
#define FOR(i, l, r) for(int i = l; i <= r; i++)
#define For(i, l, r) for(int i = l; i < r; i++)
#define all(x) x.begin(), x.end()
#define pr pair<int, int>
#define prr pair<int, pr> 
#define fi first 
#define se second
#define sze size()
#define endl '\n'
const ll LINF= 1e18 + 5;
const int ING = 1e9 + 5;
const int MOD = 1e9 + 7;
const int MAX = 1e6 + 5;
void solve()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n1, n2, n3;
        cin >> n1 >> n2 >> n3;
        ll a[n1], b[n2], c[n3];
        For(i, 0, n1) cin >> a[i];
        For(i, 0, n2) cin >> b[i];
        For(i, 0, n3) cin >> c[i];
        int l1 = 0, l2 = 0, l3 = 0, d = 0;
        bool check = 0;
        while(l1 < n1 && l2 < n2 && l3 < n3)
        {
            if(a[l1] == b[l2] && a[l1] == c[l3]) 
            {
                check = 1;
                cout << a[l1] << " ";
                l1++; l2++; l3++;
            }
            else if(a[l1] < b[l2]) l1++;
            else if(b[l2] < c[l3]) l2++;
            else l3++;
        }
        if(!check) cout << -1;
        cout << endl;
    }
}
int main()
{
    // file();
    faster();
    solve(); 
}
