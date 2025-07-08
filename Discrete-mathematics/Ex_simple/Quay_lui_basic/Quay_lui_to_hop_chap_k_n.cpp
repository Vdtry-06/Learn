#include<bits/stdc++.h>
#define file() freopen("Test.inp", "r", stdin); freopen("Test.out", "w", stdout);
#define faster() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
int a[100];
int n, k;
void inkq(){
    for(int i = 1; i <= k; i++){
        cout << a[i];
    }
    cout << endl;
}
void Try(int i){
    for(int j = a[i - 1] + 1; j <= n - k + i; j++){
        a[i] = j;
        if(i == k){
            inkq();
        }
        else Try(i + 1);
    }
}
void solve(){
    cin >> n >> k;
    Try(1);
}
int main(){
    file();
    faster();
    solve();
}
// 5 3
// 123
// 124
// 125
// 134
// 135
// 145
// 234
// 235
// 245
// 345
