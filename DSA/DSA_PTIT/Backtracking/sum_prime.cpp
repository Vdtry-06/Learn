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
int n, p, s;
int f[1005];
int a[1005];
int d = 0;
vector<string> res;
bool prime(int n){
    for(int i = 2; i * i <= n; i++){
        if(n % i == 0) return false;
    }
    return n > 1;
}
void BackTracking(int i, int be, int sum){
    for(int j = be; j <= d; j++){
        if(sum + a[j] <= s && a[j] > p){
            f[i] = a[j];
            if(sum + a[j] == s && i == n){
                string s;
                for(int idx = 1; idx <= i; idx++){
                    s += to_string(f[idx]);
                    if(idx != i) s += " ";
                }
                res.push_back(s);
                s.clear();
            }
            else BackTracking(i + 1, j + 1, sum + f[i]);
        }
    }
}
void solve(){
    cin >> n >> p >> s;
    d = 0;
    for(int i = p; i <= s; i++){
        if(prime(i)) a[d++] = i;
    }
    BackTracking(1, 1, 0);
    cout << res.size() << endl;
    for(int i = 0; i < res.size(); i++){
        cout << res[i] << endl;
    }
    res.clear();
}
int main(){
    // file();
    faster();
    int t;
    cin >> t;
    while(t--){
        solve();
        // cout << endl;
    } 
}