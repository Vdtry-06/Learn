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
        string s;
        cin >> s;
        ll sum = 0;
        reverse(s.begin(), s.end());
        if(s[0] == '1') sum = 1;
        For(i, 1, s.size())
        {
            if(s[i] == '1')
            {
                if(i % 4 == 1) sum += 2;
                else if(i % 4 == 2) sum += 4;
                else if(i % 4 == 3) sum += 8;
                else sum += 6;
            }
        }
        // cout << sum;
        if(sum % 5 == 0) cout << "Yes";
        else cout << "No";
        cout << endl;
    }
}
int main()
{
    // file();
    faster();
    solve();
}