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
class Solution {
public:
    vector<int> MaxSlidingWindow(vector<int>& a, int k) {
        vector<int> res;
        int n = a.size();
        deque<int> dq;
        for(int i = 0; i < n; ++i){
            while(!dq.empty() && dq.front() <= i - k) dq.pop_front();
            while(!dq.empty() && a[dq.back()] <= a[i]) dq.pop_back();
            dq.push_back(i);
            if(i >= k - 1) res.push_back(a[dq.front()]);
        }
        return res;
    }
};
void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int &x : a) cin >> x;
    Solution res;
    vector<int> ans = res.MaxSlidingWindow(a, k);
    for(int x: ans) cout << x << " ";
}
int main(){
    file();
    faster();
    solve();
}
// 8 3
// 1 3 -1 -3 5 3 6 7
// 3 3 5 5 6 7 