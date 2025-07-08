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
char f[1005];
string s;
int n;
void BackTracking(int i, int be){
    for(int j = be; j <= n; j++){
        f[i] = s[j - 1];
        if(i <= n){
            for(int idx = 1; idx <= i; idx++){
                cout << f[idx];
            }
            cout << " ";
        }
        BackTracking(i + 1, j + 1);
    }
}
void solve(){
    cin >> n >> s;
    n = s.size();
    BackTracking(1, 1);
}
int main(){
    file();
    faster();
    int t;
    cin >> t;
    while(t--){
        solve();
        cout << endl;
    } 
}