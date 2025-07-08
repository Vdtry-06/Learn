#include<bits/stdc++.h>
#define file() freopen("Test.inp", "r", stdin); freopen("Test.out", "w", stdout);
#define faster() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
int a[100];
int n;
void inkq(){
    for(int i = 1; i <= n; i++){
        cout << a[i];
    }
    cout << endl;
}
void Try(int i){
    for(int j = 0; j <= 1; j++){
        a[i] = j;
        if(i == n){
            inkq();
        }
        else Try(i + 1);
    }
}
void solve(){
    cin >> n;
    Try(1);
}
int main(){
    file();
    faster();
    solve();
}