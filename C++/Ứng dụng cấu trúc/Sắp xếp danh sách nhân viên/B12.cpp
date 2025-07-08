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
struct NhanVien
{
    string mnv, ht, gt, ns, dc, mst, nkhd;
    int ngay, thang, nam;
};
int z = 0;
void nhap(NhanVien &ds)
{
    if(z == 0) cin.ignore();
    z++;
    getline(cin, ds.ht);
    getline(cin, ds.gt);
    getline(cin, ds.ns);
    getline(cin, ds.dc);
    getline(cin, ds.mst);
    getline(cin, ds.nkhd);
    ds.thang = (ds.ns[0] - '0') * 10 + ds.ns[1] - '0';
    ds.ngay = (ds.ns[3] - '0') * 10 + ds.ns[4] - '0';
    ds.nam = (ds.ns[6] - '0') * 1000 + (ds.ns[7] - '0') * 100 + (ds.ns[8] - '0') * 10 + ds.ns[9] - '0';
}
bool cmp(NhanVien a, NhanVien b)
{
    if(a.nam == b.nam)
    {
        if(a.thang == b.thang)
        {
            return a.ngay < b.ngay;
        }
        return a.thang < b.thang;
    }
    return a.nam < b.nam;
}
void sapxep(NhanVien ds[], int n)
{
    For(i, 0, n)
    {
        if(i < 9) ds[i].mnv = "0000" + to_string(i + 1);
        else ds[i].mnv = "000" + to_string(i + 1);
    }
    sort(ds, ds + n, cmp);
}
void inds(NhanVien ds[], int n)
{
    For(i, 0, n)
    {
        cout << ds[i].mnv << " " << ds[i].ht << " " << ds[i].gt << " " << ds[i].ns << " " << ds[i].dc << " " << ds[i].mst << " " << ds[i].nkhd << endl;
    }
}
int main(){
    struct NhanVien ds[50];
    int N,i;
    cin >> N;
    for(i = 0; i < N; i++) nhap(ds[i]);
    sapxep(ds, N);
    inds(ds, N);
    return 0;
}