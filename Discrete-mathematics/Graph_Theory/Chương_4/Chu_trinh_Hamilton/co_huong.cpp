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
vector<int> ke[MAX];
vector<int> res;
bool used[MAX];
bool check;
int n, m;
void init(){
    memset(used, false, sizeof(used));
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        ke[x].push_back(y);
    }
}
void DFS(int u, int be, int cnt){
    used[u] = true;
    res.push_back(u);
    if(cnt == n){
        if(find(ke[u].begin(), ke[u].end(), be) != ke[u].end()){
            check = true;
            for(int x: res) cout << x << " ";
            cout << be << endl;
        }
    }
    for(int x : ke[u]){
        if(!used[x]){
            DFS(x, be, cnt + 1);
        }
    }
    used[u] = false;
    res.pop_back();
}
void solve(){
    init();
    memset(used, false, sizeof(used));
    check = false;
    DFS(1, 1, 1);
    if(!check) cout << -1;
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