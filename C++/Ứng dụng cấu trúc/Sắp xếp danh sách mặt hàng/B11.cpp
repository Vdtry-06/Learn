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
// #define se second
#define sze size()
#define endl '\n'
const ll LINF= 1e18 + 5;
const int ING = 1e9 + 5;
const int MOD = 1e9 + 7;
const int MAX = 1e6 + 5;
struct mathang
{
    string mmh, tmh, nmh;
    double gm, gb, ln;
};
void nhap(mathang ds[], int n)
{
    For(i, 0, n)
    {
        cin.ignore();
        getline(cin, ds[i].tmh);
        getline(cin, ds[i].nmh);
        cin >> ds[i].gm;
        cin >> ds[i].gb;
        ds[i].mmh = to_string(i + 1);
        ds[i].ln = ds[i].gb - ds[i].gm;
    }
}
bool cmp(mathang a, mathang b)
{
    return a.ln > b.ln;
}
void sapxep(mathang ds[], int n)
{
    sort(ds, ds + n, cmp);
}
void in(mathang ds[], int n)
{
    For(i, 0, n)
    {
        cout << ds[i].mmh << " " << ds[i].tmh << " " << ds[i].nmh << " " << fixed << setprecision(2) << ds[i].ln << endl;
    }
}
void solve()
{
    mathang ds[50];
    int n;
    cin >> n;
    nhap(ds, n);
    sapxep(ds, n);
    in(ds, n);
}
int main()
{
    // file();
    faster();
    solve();
}