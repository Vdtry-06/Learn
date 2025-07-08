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
void solve(){
    int n;
    cin >> n;
    unordered_map<int, int> mp;
    queue<int> q;
    q.push(n);
    while(mp[1] == 0){
        int top = q.front(); q.pop();
        if(mp[top - 1] == 0){
            q.push(top - 1);
            mp[top - 1] = mp[top] + 1;
        }
        for(int i = 2; i * i <= top; i++){
            if(top % i == 0){
                int mx = max({top / i, i});
                if(mp[mx] == 0){
                    q.push(mx);
                    mp[mx] = mp[top] + 1;
                }
            }
        }
        
    }
    cout << mp[1];
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