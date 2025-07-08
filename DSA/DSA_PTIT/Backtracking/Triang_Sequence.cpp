#include<bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using ll = long long;
#define file() freopen("Test.inp", "r", stdin); freopen("Test.out", "w", stdout);
#define faster() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pq_min priority_queue<ll, vector<ll>, greater<ll>> 
#define pq_max priority_queue<int> 
#define pr pair<int, int>
#define se second
#define fi first
#define endl '\n'
const ll LINF= 1e18 + 5;
const int ING = 1e9 + 5;
const int MOD = 1e9 + 7;
const int MAX = 1e5 + 5;
int n;
void Backtracking(vector<int> &a){
    int n = a.size();
    if(n == 0) return;
    for(int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;
    vector<int> b(n - 1);
    for(int i = 1; i < n; i++){
        b[i - 1] = a[i - 1] + a[i];
    }
    Backtracking(b);
}
void solve(){
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    Backtracking(a);
}
signed main(){
    faster();
    file();
    solve();
}