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
int f[1005];
int n;
void Backtracking(int i){
    for(int j = 0; j <= 1; j++){
        f[i] = j;
        if(i == n){
            for(int idx = 1; idx <= i; idx++){
                cout << f[idx] << " ";
            }
            cout << endl;
        } 
        else Backtracking(i + 1);
    }
}
void solve(){
    cin >> n;
    Backtracking(1);
}
signed main(){
    faster();
    file();
    solve();
}