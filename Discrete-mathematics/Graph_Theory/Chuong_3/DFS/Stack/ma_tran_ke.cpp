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
bool used[1005];
void init(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    }
    memset(used, false, sizeof(used));
}
void DFS(int u){
    stack<int> st;
    vector<int> v;
    st.push(u);
    used[u] = true;
    v.push_back(u);
    while(!st.empty()){
        int dinh = st.top();
        st.pop();
        for(int i = 1; i <= n; i++){
            if(!used[i] && a[dinh][i] == 1){
                st.push(dinh);
                st.push(i);
                v.push_back(i);
                used[i] = true;
                break;
            }
        }
    }
    for(int x : v) cout << x << " ";
}
void solve(){
    init();
    DFS(1);
}
int main(){
    // file();
    faster();
    solve();
}