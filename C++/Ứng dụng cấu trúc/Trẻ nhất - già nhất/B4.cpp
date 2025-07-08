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
struct tregia
{
    string ten, ns;
    int ngay, thang, nam;
};
void nhap(tregia ds[], int n)
{
    For(i, 0, n)
    {
        cin >> ds[i].ten >> ds[i].ns;
        ds[i].ngay = (ds[i].ns[0] - '0') * 10 + ds[i].ns[1] - '0';
        ds[i].thang = (ds[i].ns[3] - '0') * 10 + ds[i].ns[4] - '0';
        ds[i].nam = (ds[i].ns[6] - '0') * 1000 + (ds[i].ns[7] - '0') * 100 + (ds[i].ns[8] - '0') * 10 + ds[i].ns[9] - '0';
    }
}
bool cmp(tregia a, tregia b)
{
    if(a.nam == b.nam)
    {
        if(a.thang == b.thang)
        {
            return a.ngay > b.ngay;
        }
        return a.thang > b.thang;
    }
    return a.nam > b.nam;
}
void solve()
{
    tregia ds[100];
    int n;
    cin >> n;
    cin.ignore();
    nhap(ds, n);
    sort(ds, ds + n, cmp);
    // For(i, 0, n)
    // {
    //     cout << ds[i].ten << " " << ds[i].ns << endl;
    // }
    cout << ds[0].ten << endl << ds[n - 1].ten;
}
signed main()
{
    // file();
    faster();
    solve();
}