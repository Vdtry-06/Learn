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
int a[1005][1005];
bool used[1005];
vector<pr> tree;
void init(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> a[i][j];
            if(a[i][j] && i < j){
                ke[i].push_back(j);
            }
        }
    }
    memset(used, false, sizeof(used));
}
void Tree_DFS(int u){
    used[u] = true;
    for(int v : ke[u]){
        if(!used[v]){
            tree.push_back({u, v});
            Tree_DFS(v);
        }
    }
    for(auto x : tree) cout << x.fi << " " << x.se << endl;
    tree.clear();
}
void solve(){
    init();
    Tree_DFS(1);
}
int main(){
    // file();
    faster();
    solve();
}