#include<bits/stdc++.h>
#define file() freopen("Test.inp", "r", stdin); freopen("Test.out", "w", stdout);
#define faster() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
int cot[100], cc[100], cp[100];
int a[100][100], x[100];
int n, cnt = 0;
void ktao(){
    for(int i = 1; i <= 100; i++){
        cot[i] = cc[i] = cp[i] = 1;
    }
}
void kq(){
    memset(a, 0, sizeof(a));
    for(int i = 1; i <= n; i++){
        a[i][x[i]] = 1;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cout << a[i][j];
        }
        cout << endl;
    }
    cout << endl;
}
void Try(int i){
    for(int j = 1; j <= n; j++){
        if(cot[j] && cc[i - j + n] && cp[j + i - 1]){
            x[i] = j;
            cot[j] = cc[i - j + n] = cp[j + i - 1] = 0;
            if(i == n){
                cnt++;
                kq();
            }
            else Try(i + 1);
            cot[j] = cc[i - j + n] = cp[j + i - 1] = 1;
        }
    }
}
int main(){
    file();
    cin >> n;
    ktao();
    Try(1);
    cout << cnt;
}