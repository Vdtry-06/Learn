#include<bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using ll = long long;
#define file() freopen("Test.inp", "r", stdin); freopen("Test.out", "w", stdout);
#define faster() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pq_min priority_queue<ll, vector<ll>, greater<ll>> 
#define pq_max priority_queue<int> 
#define pr pair<int, int>
#define se second
#define fi first
#define endl '\n'
const ll LINF= 1e18 + 5;
const int ING = 1e9 + 5;
const int MOD = 1e9 + 7;
const int MAX = 1e5 + 5;
bool check;
int a[MAX];
int n;
void Init(){
    for(int i = 1; i <= n; i++) a[i] = i;
}
void Generation(){
    int i = n;
    while(i >= 1 && a[i] > a[i + 1]) i--;
    if(i == 0) check = false;
    else{
        int j = n;
        while(a[i] > a[j]) j--;
        swap(a[i], a[j]);
        sort(a + i + 1, a + n + 1);
    }
}
void solve(){
    cin >> n;
    check = true;
    Init();
    while(check){
        for(int i = 1; i <= n; i++) cout << a[i];
        Generation();
        cout << endl;
    }
}
signed main(){
    faster();
    file();
    solve();
}