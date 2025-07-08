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
const int MAX = 1e5 + 5;
int a[MAX];
int h[MAX];
int n, m;
vector<pair<int, int>> res;
void solve(){
    cin >> n >> m;
    memset(h, 0, sizeof(h));
    int mx = INT_MIN;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[j];
            if(a[j]) h[j]++;
            else h[j] = 0;
        }
        stack<int> st;
        int j = 0;
        while(j < m){
            if(st.empty() || h[st.top()] <= h[j]){
                st.push(j);
                j++;
            }
            else {
                int idx = st.top(); st.pop();
                if(st.empty()) {
                    if(mx <= j * h[idx]){
                        mx = j * h[idx];
                        res.push_back({j, h[idx]});
                    }
                }
                else{
                    if(mx <= (j - st.top() - 1) * h[idx]){
                        mx = (j - st.top() - 1) * h[idx];
                        res.push_back({j - st.top() - 1, h[idx]});
                    }
                }
            }
        }
        while(!st.empty()){
            int idx = st.top(); st.pop();
            if(st.empty()) {
                if(mx <= j * h[idx]){
                    mx = j * h[idx];
                    res.push_back({j, h[idx]});
                }
            }
            else{
                if(mx <= (j - st.top() - 1) * h[idx]){
                    mx = (j - st.top() - 1) * h[idx];
                    res.push_back({j - st.top() - 1, h[idx]});
                }
            }
        }
    }
    int mi = INT_MAX, c1, c2;
    for(pair<int, int> x : res){
        if(mx == x.fi * x.se){
            if(mi > abs(x.fi - x.se)){
                mi = abs(x.fi - x.se);
                c1 = min(x.fi, x.se);
                c2 = max(x.fi, x.se);
            }
        }
    }
    cout << c1 << " " << c2;
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
// 4
// 4 6
// 1 1 1 1 1 1
// 1 1 1 0 0 0
// 0 0 0 1 0 1
// 0 1 0 0 1 0
// 2 3
// 1 1 1
// 1 1 0
// 4 8
// 1 0 0 0 0 1 1 0
// 1 0 0 0 0 1 1 0
// 1 0 0 0 0 0 0 0
// 1 0 0 0 0 0 0 0
// 11 13
// 0 0 0 0 0 1 0 0 0 0 0 0 0
// 0 0 0 0 1 1 1 0 0 0 0 0 0
// 0 0 1 1 1 1 1 1 1 0 0 0 0
// 0 0 1 1 1 1 1 1 1 0 0 0 0
// 0 1 1 1 1 1 1 1 1 1 0 0 0
// 1 1 1 1 1 1 1 1 1 1 1 0 0
// 0 1 1 1 1 1 1 1 1 1 0 0 0
// 0 0 1 1 1 1 1 1 1 0 0 0 0
// 0 0 1 1 1 1 1 1 1 0 0 0 0
// 0 0 0 0 1 1 1 0 0 0 0 1 1
// 0 0 0 0 0 1 0 0 0 0 0 1 1

// 2 3
// 2 2
// 2 2
// 7 7
