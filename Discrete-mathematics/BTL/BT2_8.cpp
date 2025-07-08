#include<bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using ll = long long;
#define file() freopen("Test.inp", "r", stdin); freopen("Test.out", "w", stdout);
#define faster() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pq_min priority_queue<ll, vector<ll>, greater<ll>> 
#define pq_max priority_queue<int> 
#define FORD(i, r, l) for(int i = r; i >= l; i--)
#define FOR(i, l, r) for(int i = l; i <= r; i++)
#define For(i, l, r) for(int i = l; i < r; i++)
#define pr pair<int, int>
#define se second
#define fi first
#define endl '\n'
const ll LINF= 1e18 + 5;
const int ING = 1e9 + 5;
const int MOD = 1e9 + 7;
const int MAX = 1e6 + 5;
int a[100][100]; 
vector<int> v;
string cp;
int n, x[1000], k, d = 0;
bool check = false;
void Try(int i, int bd, int s)
{ 
    For(j, bd, v.size())
    {
        x[i] = v[j];
        if(s + v[j] == k)
        {
            check = true;
            FOR(idx, 1, i) 
            {
                cp += to_string(x[idx]);
                cp += " ";
            }
            cp += "\n";
            d++;
            check = false;
        }
        else Try(i + 1, j + 1, s + x[i]);
    }
    
}
// i là số lượng phần tử thỏa mãn
// bd là vị trí phần tử đầu tiên thỏa mãn 
// s là tổng của các phần tử 
void solve()
{
    FOR(i, 1, n)
    {
        FOR(j, 1, n) v.push_back(a[i][j]);
        d = 0;
        Try(1, 0, 0);
        cout << "so cach chon hang " << i << " la : " << d << endl;
        For(j, 0, cp.size()) cout << cp[j];
        v.clear(); cp.clear();
        cout << endl;
    }
    FOR(j, 1, n)
    {
        FOR(i, 1, n) v.push_back(a[i][j]); 
        d = 0;
        Try(1, 0, 0);
        cout << "so cach chon cot " << j << " la : " << d << endl;
        For(i, 0, cp.size()) cout << cp[i];
        v.clear(); cp.clear();
        cout << endl;
    }
}
signed main()
{
    file();
    // cout << "Nhap do dai ma tran vuong A: ";
    cin >> n;
    // cout << "Nhap tong cua phan tu dang xet la: ";
    cin >> k;
    // cout << "Nhap ma tran A cap " << n << endl;
    FOR(i, 1, n)
    {
        FOR(j, 1, n) cin >> a[i][j];
    }
    faster();
    solve();
}
