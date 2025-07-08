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
    string na, se, ns, add, th,  nk;
};
int z = 0;
void nhap(NhanVien &a)
{
    if(z == 0) cin.ignore();
    z++;
    getline(cin, a.na);
    getline(cin, a.se);
    getline(cin, a.ns);
    getline(cin, a.add);
    getline(cin, a.th);
    getline(cin, a.nk);
}
void inds(NhanVien ds[],int n)
{
    string s = "";
    For(i, 0, n)
    {
        if(i < 9) s = "0000";
        else s = "000";
        cout << s << i + 1 << " " << ds[i].na << " " << ds[i].se 
        << " " << ds[i].ns << " " << ds[i].add << " " << ds[i].th << " " << ds[i].nk << endl;
    }
}
int main(){
    struct NhanVien ds[50];
    int N,i;
    cin >> N;
    for(i = 0; i < N; i++) nhap(ds[i]);
    inds(ds,N);
    return 0;
}