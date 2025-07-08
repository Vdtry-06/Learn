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
// b1: DFS tren G: luu vao 1 stack
// b2: xay dung do thi lat nguoc TG: tu x -> y chuyen thanh y -> x
// b3: pop cac dinh trong stack o b1 va goi DFS tren TG
// O(2 *(v + e))
// lien thong manh: Strongly connected components: SCC
int n, m;
vector<int> ke[1005], r_ke[1005];
stack<int> st;
bool used[1005];
void init(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        ke[x].push_back(y);
        r_ke[y].push_back(x);
    }
}
void DFS1(int u){
    used[u] = true;
    for(int x : ke[u]){
        if(!used[x]){
            DFS1(x);
        }
    }
    // da duyet xong dinh u
    st.push(u);
    // cout << u << " ";
}
void DFS2(int u){
    used[u] = true;
    // cout << u << " ";
    for(int x: r_ke[u]){
        if(!used[x]){
            DFS2(x);
        }
    }
}
void SCC(){
    memset(used, false, sizeof(used));
    // B1: goi do thi DFS tren do thi ban dau
    for(int i = 1; i <= n; i++){
        if(!used[i]){
            DFS1(i);
        }
    }
    // cout << endl;
    int cnt = 0;
    memset(used, false, sizeof(used));
    while(!st.empty()){
        int u = st.top(); st.pop();
        if(!used[u]){
            DFS2(u);
            cnt++;
            // cout << endl;
        }
    }
    if(cnt == 1) cout << "DO THI LIEN THONG MANH";
    else cout << "DO THI KHONG LIEN THONG MANH";
}
void solve(){
    init();
    SCC();
}
int main(){
    // file();
    faster();
    solve();
}