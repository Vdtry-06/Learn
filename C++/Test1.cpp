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
const int MAX = 1e5 + 5;
int a[MAX];
int n;
void solve(){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    stack<int> st;
    ll mx = INT_MIN, i  = 0;
    while(i < n){
        if(st.empty() || a[st.top()] <= a[i]){
            st.push(i);
            i++;
        }
        else{
            int idx = st.top(); st.pop();
            if(st.empty()) mx = max(mx, i * a[idx]);
            else mx = max(mx, (i - st.top() - 1) * a[idx]);
        }
    }
    while(!st.empty()){
        int idx = st.top(); st.pop();
            if(st.empty()) mx = max(mx, i * a[idx]);
            else mx = max(mx, (i - st.top() - 1) * a[idx]);
    }
    cout << mx;
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