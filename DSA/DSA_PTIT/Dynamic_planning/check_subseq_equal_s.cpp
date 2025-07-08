#include<bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using ll = long long;
#define file() freopen("Test.inp", "r", stdin); freopen("Test.out", "w", stdout);
#define faster() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pq_min priority_queue<ll, vector<ll>, greater<ll>> 
#define pq_max priority_queue<int> 
#define pr pair<int, int>
#define prr pair<int, pr> 
#define se second
#define fi first
#define endl '\n'
const ll LINF= 1e18 + 5;
const int ING = 1e9 + 5;
const int MOD = 1e9 + 7;
const int MAX = 1e6 + 5;
bool f[40005];
int a[205];
int n, s;
void solve(){
    cin >> n >> s;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] %= s;
    }
    memset(f, false, sizeof(f));
    f[0] = true;
    for(int i = 1; i <= n; i++){
        for(int j = s; j >= a[i]; j--){
            if(f[j - a[i]]) f[j] = true;
        }
    }
    if(f[s]) cout << "YES";
    else cout << "NO";
}
int main(){
    // file();
    faster();
    int t;
    cin >> t;
    while(t--){
        solve();
        cout << endl;
    }
}