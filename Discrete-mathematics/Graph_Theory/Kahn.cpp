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
// tinh ban bac vao
// dua vao hang doi
// hang doi chua rong thi lay dinh dau hang doi xoa ra khoi do thi
// ung dung: xac dinh chu trinh tren do thi co huong
int n, m;
vector<int> ke[1005];
vector<int> topo;
int in[1005];
void init(){
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int x, y;
        cin >> x >> y;
        ke[x].push_back(y);
        in[y]++;
    }
}
void Kahn(){
    queue<int> q;
    for(int i = 1; i <= n; i++){
        if(in[i] == 0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int u = q.front(); q.pop();
        topo.push_back(u);
        for(int v: ke[u]){
            in[v]--;
            if(in[v] == 0){
                q.push(v);
            }
        }
    }
    for(int x: topo) cout << x << " ";
}
void solve(){
    init();
    Kahn();
}
int main(){
    // file();
    faster();
    solve();
}