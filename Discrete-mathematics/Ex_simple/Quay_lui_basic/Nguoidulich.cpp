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
#define prr pair<int, pr> 
#define se second
#define fi first
#define endl '\n'
const ll LINF= 1e18 + 5;
const int ING = 1e9 + 5;
const int MOD = 1e9 + 7;
const int MAX = 1e6 + 5;
int mi = MAX, cmin = MAX;
int c[105][105];
int used[105];
int x[105];
int d = 0;
int n;
void Try(int i){
    FOR(j, 1, n){
        if(!used[j]){
            x[i] = j;
            used[j] = 1;
            d += c[x[i - 1]][x[i]];
            if(i == n){
                mi = min(mi, d + c[x[n]][1]);
            }
            else if(d + (n - i + 1) * cmin < mi) Try(i + 1);
            used[j] = 0;
            d -= c[x[i - 1]][x[i]];
        }
    }
}
void solve(){
    cin >> n;
    FOR(i, 1, n){
        FOR(j, 1, n) {
            cin >> c[i][j];
            if(c[i][j] != 0) cmin = min(cmin, c[i][j]);
        }
    }
    memset(used, 0, sizeof(used));
    x[1] = 1;
    used[1] = 1;
    Try(2);
    cout << mi;
}
int main(){
    file();
    faster();
    solve();
}