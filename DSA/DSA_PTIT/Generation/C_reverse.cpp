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
bool check;
int a[MAX];
int n, k;

void Generation(){
    int i = k;
    while(i >= 1 && a[i] == a[i - 1] + 1) i--;
    if(i >= 1){
        a[i]--;
        for(int j = i + 1; j <= k; j++) a[j] = n - k + j;
    }
    else{
        for(int j = 1; j <= k; j++) a[j] = n - k + j;
    }
}
void solve(){
    cin >> n >> k;
    for(int i = 1; i <= k; i++) cin >> a[i];
    Generation();
    for(int i = 1; i <= k; i++) cout << a[i] << " ";
}
signed main(){
    faster();
    file();
    int t;
    cin >> t;
    while(t--){
        solve();
        cout << endl;
    }
}