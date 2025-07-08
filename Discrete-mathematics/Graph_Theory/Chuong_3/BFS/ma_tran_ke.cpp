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
bool used[1005];
void init(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> a[i][j];
            if(a[i][j] == 1){
                ke[i].push_back(j);
            }
        }
    }
    memset(used, false, sizeof(used));
}
void BFS(int u){
    queue<int> q;
    q.push(u);
    used[u] = true;
    while(!q.empty()){
        int v = q.front();
        cout << v << " ";
        q.pop();
        for(int x : ke[v]){
            if(!used[x]){
                q.push(x);
                used[x] = true;
            }
        }
    }
}
void solve(){
    init();
    BFS(1);
}
int main(){
    // file();
    faster();
    solve();
}