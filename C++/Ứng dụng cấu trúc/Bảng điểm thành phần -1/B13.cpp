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
struct SinhVien
{
    string msv, tsv, l;
    double a, b, c;
};
void nhap(SinhVien &ds)
{
    cin.ignore();
    getline(cin, ds.msv);
    getline(cin, ds.tsv);
    getline(cin, ds.l);
    cin >> ds.a >> ds.b >> ds.c;
}
bool cmp(SinhVien a, SinhVien b)
{
    return a.msv < b.msv;
}
void sap_xep(SinhVien ds[], int n)
{
    sort(ds, ds + n, cmp);
}
void in_ds(SinhVien ds[], int n)
{
    For(i, 0, n)
    {
        cout << i + 1 << " " << ds[i].msv << " " << ds[i].tsv << " " << ds[i].l << " ";
        cout << fixed << setprecision(1) << ds[i].a << " " << ds[i].b << " " << ds[i].c << endl;
    }
}

int main(){
    int n;
    cin >> n;
    struct SinhVien *ds = new SinhVien[n];
    for(int i = 0; i < n; i++) {
    	nhap(ds[i]);
	}
	sap_xep(ds, n);
    in_ds(ds,n);
    return 0;
}