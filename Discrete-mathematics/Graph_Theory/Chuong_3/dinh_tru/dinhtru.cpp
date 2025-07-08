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
int a[1005][1005];
vector<int> ke[1005];
int parent[1005];
bool used[1005];
void init(){
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int x, y;
        cin >> x >> y;
        ke[x].push_back(y);
        // ke[y].push_back(x);
    }
}
void DFS(int u){
    used[u] = true;
    for(int x : ke[u]){
        if(!used[x]){
            DFS(x);
            used[x] = true;
        }
    }
}
void dinh_tru(){
    int ans = 0;
    int tplt = 0;
    memset(used, false, sizeof(used));
    for(int i = 1; i <= n; i++){
        if(!used[i]){
            tplt++;
            DFS(i);
        }
    }
    for(int i = 1; i <= n; i++){
        memset(used, false, sizeof(used));
        used[i] = true; // loai bo dinh i khoi do thi
        int d = 0; // dem so tplt khi loai bo dinh i
        for(int j = 1; j <= n; j++){
            if(!used[j]){
                d++;
                DFS(j);
            }
        }
        if(d > tplt){
            cout << i << " ";
            ans++;
        }
    }
    // cout << ans << endl;
}
void solve(){
    init();
    dinh_tru();
}
int main(){
    // file();
    faster();
    solve();
}