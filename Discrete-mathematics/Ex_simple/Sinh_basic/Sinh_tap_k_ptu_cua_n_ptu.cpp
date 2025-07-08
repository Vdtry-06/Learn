#include<bits/stdc++.h>
#define file() freopen("Test.inp", "r", stdin); freopen("Test.out", "w", stdout);
#define faster() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
bool check;
int a[100];
int n, k;
void init(){
    for(int i = 1; i <= k; i++){
        a[i] = i;
    }
}
void sinh(){
    int i = k;
    while(i >= 1 && a[i] == n - k + i){
        i--;
    }
    if(i == 0) check = 0;
    else{
        a[i]++;
        for(int j = i + 1; j <= k; j++){ // 125 -> 134
            a[j] = a[j - 1] + 1;
        }
    }
}
void solve(){
    cin >> n >> k;
    init();
    check = 1;
    while(check){
        for(int i = 1; i <= k; i++){
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
