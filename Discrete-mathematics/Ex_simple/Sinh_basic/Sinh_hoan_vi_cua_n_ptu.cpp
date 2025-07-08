#include<bits/stdc++.h>
#define file() freopen("Test.inp", "r", stdin); freopen("Test.out", "w", stdout);
#define faster() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
bool check;
int a[100];
int n;
void init(){
    for(int i = 1; i <= n; i++){
        a[i] = i;
    }
}
void sinh(){
    int i = n;
    while(i >= 1 && a[i] > a[i + 1]){
        i--;
    }
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
    init();
    check = true;
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
// 123
// 132
// 213
// 231
// 312
// 321
