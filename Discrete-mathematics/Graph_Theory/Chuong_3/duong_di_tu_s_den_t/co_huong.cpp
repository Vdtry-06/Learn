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
int n, m, s, t;
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
    
    cin >> s >> t;
}
void DFS(int u){
    used[u] = true;
    for(int x : ke[u]){
        if(!used[x]){
            parent[x] = u;
            DFS(x);
            used[x] = true;
        }
    }
}
void BFS(int u){
    queue<int> q;
    q.push(u);
    used[u] = true;
    while(!q.empty()){
        int t = q.front(); q.pop();
        for(int x : ke[t]){
            if(!used[x]){
                q.push(x);
                used[x] = true;
                parent[x] = t;
            }
        }
    }
}
void Path(int s, int t){
    memset(used, false, sizeof(used));
    memset(parent, 0, sizeof(parent));
    // DFS(s);
    BFS(s);
    if(!used[t]){
        cout << "Khong co duong di";
    }
    else{
        // truy vet duong di
        vector<int> path;
        while(t != s){
            path.push_back(t);
            // lat nguoc lai
            t = parent[t];
        }
        path.push_back(s);
        reverse(path.begin(), path.end());
        for(int x : path){
            cout << x << " ";
        }
    }
}
void solve(){
    init();
    Path(s, t);
}
int main(){
    // file();
    faster();
    solve();
}