#include<bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using ll = long long;
#define file() freopen("Test.inp", "r", stdin); freopen("Test.out", "w", stdout);
#define faster() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pr pair<int, int>
#define prr pair<int, pr> 
#define se second
#define fi first
const ll LINF= 1e18 + 5;
const int ING = 1e9 + 5;
const int MOD = 1e9 + 7;
const int MAX = 1e6 + 5;
int n, m;
vector<int> ke[1005];
vector<pr> dscanh;
bool used[1005];
int check = 1;
void init(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        ke[x].push_back(y);
        ke[y].push_back(x);
        dscanh.push_back({x, y});
    }
}
void DFS(int u){
    used[u] = true;
    for(int v: ke[u]){
        if(!used[v]){
            DFS(v);
            used[v] = true;
        }
    }
}
void DFS2(int u, int s, int t){
    used[u] = true;
    for(int v : ke[u]){
        if((u == s && v == t) || (u == t && v == s)) continue;
        if(!used[v]){
            DFS2(v, s, t);
        }
    }
}
void canh_cau(){
    int ans = 0;
    int tplt = 0;
    memset(used, false, sizeof(used));
    for(int i = 1; i <= n; i++){
        if(!used[i]){
            DFS(i);
            tplt++;
        }
    }
    for(auto it: dscanh){
        int x = it.fi;
        int y = it.se;
        memset(used, false, sizeof(used));
        int d = 0;
        for(int i = 1; i <= n; i++){
            if(!used[i]){
                DFS2(i, x, y);
                d++;
            }
        }
        if(d > tplt){
            // ans++;
            // cout << x << " " << y << endl;
            check = 0;
        }
    }
    // cout << ans << endl;
    if(check) cout << "DO THI DINH CHIEU DUOC";
    else cout << "DO THI KHONG DINH CHIEU DUOC";
}
void solve(){
    init();
    canh_cau();
}
int main(){
    // file();
    faster();
    solve();
}