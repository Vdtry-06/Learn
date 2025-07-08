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
set<int> ke[1005];
int step_in[1005], step_out[1005];
bool used[1005];
int n, m;
void init(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        ke[x].insert(y);
        step_in[x]++;
        step_out[y]++;
    }
    memset(used, false, sizeof(used));
}
// dk: - lien thong yeu
//     - ton tai 2 dinh u, v : deg+u - deg-u = deg-v - deg+v = 1
//     - cac dinh con lai deg+ = deg-
void euler(int u){
    stack<int> st;
    vector<int> EC;
    st.push(u);
    while(!st.empty()){
        int x = st.top();
        if(ke[x].size() != 0){
            int y = *ke[x].begin();
            st.push(y);
            ke[x].erase(y);
            ke[y].erase(x);
        }
        else{
            st.pop();
            EC.push_back(x);
        }
    }
    reverse(EC.begin(), EC.end());
    for(int x : EC) cout << x << " ";
}
void solve(){
    init();
    int gt = 0;
    for(int i = 1; i <= n; i++){
        if(step_out[i] - step_in[i] == 1){
            gt = i;
            break;
        }
    }
    euler(gt);
}
int main(){
    // file();
    faster();
    solve();
}