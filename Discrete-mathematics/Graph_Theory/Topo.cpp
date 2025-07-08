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
// dk: do thi ko co chu trinh
// dinh u truoc dinh v: do thi co huong
int n, m;
vector<int> ke[1005];
bool used[1005];
vector<int> topo;
void init(){
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int x, y;
        cin >> x >> y;
        ke[x].push_back(y);
    }
    memset(used, false, sizeof(used));
}
void DFS(int u){
    used[u] = true;
    for(int x : ke[u]){
        if(!used[x]) DFS(x);
    }
    topo.push_back(u);
}
void solve(){
    init();
    for(int i = 1; i <= n; i++){
        if(!used[i]){
            DFS(i);
        }
    }
    reverse(topo.begin(), topo.end());
    for(int x : topo) cout << x << " ";
}
int main(){
    // file();
    faster();
    solve();
}