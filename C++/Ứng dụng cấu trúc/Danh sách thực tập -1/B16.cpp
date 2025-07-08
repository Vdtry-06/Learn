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
struct internship
{
    string stt, msv, ht, l, email, dn;
};
void nhap(internship ds[], int n)
{
    cin.ignore();
    For(i, 0, n)
    {
        getline(cin, ds[i].msv);
        getline(cin, ds[i].ht);
        getline(cin, ds[i].l);
        getline(cin, ds[i].email);
        getline(cin, ds[i].dn);
        ds[i].stt = to_string(i + 1);
    }
}
bool cmp(internship a, internship b)
{
    return a.ht < b.ht;
}
void sapxep(internship ds[], int n)
{
    sort(ds, ds + n, cmp);
}
void in(internship ds[], int n, string s)
{
    For(i, 0, n)
    {
        if(ds[i].dn == s)
        {
            cout << ds[i].stt << " " << ds[i].msv << " " << ds[i].ht << " " << ds[i].l << " " << ds[i].email << " " << ds[i].dn << endl;
        }
    }
}
void solve()
{
    internship ds[100];
    int n;
    cin >> n;
    nhap(ds, n);
    sapxep(ds, n);
    int t;
    cin >> t;
    cin.ignore();
    while(t--)
    {
        string s;
        cin >> s;
        in(ds, n, s);
    }
}
int main()
{
    // file();
    faster();
    solve();
}