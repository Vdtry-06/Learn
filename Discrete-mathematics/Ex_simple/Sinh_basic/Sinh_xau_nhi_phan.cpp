#include<bits/stdc++.h>
#define file() freopen("Test.inp", "r", stdin); freopen("Test.out", "w", stdout);
#define faster() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
bool check;
int a[100];
int n;
void init(){
    for(int i = 1; i <= n; i++) a[i] = 0;
}
void sinh(){
    int i = n;
    while(i >= 1 && a[i] == 1){
        a[i] = 0;
        i--;
    }
    if(i == 0) check = 0;
    else a[i] = 1;
}
void solve(){
    cin >> n;
    init();
    check = 1;
    while(check){
        for(int i = 1; i <= n; i++){
            cout << a[i];
        }
        sinh();
        cout << endl;
    }
}
int main(){
    file();
    faster();
    solve();
}
// 3
// 000
// 001
// 010
// 011
// 100
// 101
// 110
// 111