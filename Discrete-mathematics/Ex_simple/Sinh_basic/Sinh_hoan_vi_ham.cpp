#include<bits/stdc++.h>
#define file() freopen("Test.inp", "r", stdin); freopen("Test.out", "w", stdout);
#define faster() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
int a[100];
int n;
void init(){
    for(int i = 1; i <= n; i++){
        a[i] = i;
    }
}
void init_dao(){
    for(int i = 1; i <= n; i++){
        a[i] = n - i + 1;
    }
}
void solve(){
    cin >> n;
    init();
    do{
        for(int i = 1; i <= n; i++){
            cout << a[i];
        }
        cout << endl;
    }while(next_permutation(a + 1, a + n + 1));
    // while(prev_permutation(a + 1, a + n + 1));
}
int main(){
    file();
    faster();
    solve();
}