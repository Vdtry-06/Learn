#include<bits/stdc++.h>
using namespace std;
#define file() freopen("Test.inp", "r", stdin); freopen("Test.out", "w", stdout);
#define faster() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
int n, a[1000];
bool used[1000];
void kq(){
    for(int i = 1; i <= n; i++){
        cout << a[i];
    }
    cout << endl;
}
void Try(int i){
    for(int j = 1; j <= n; j++){
        if(!used[j]){
            used[j] = 1;
            a[i] = j;
            if(i == n) kq();
            else Try(i + 1);
            used[j] = 0;
        }
    }
}
int main(){
    file();
    faster();
    cin >> n;
    Try(1);
}