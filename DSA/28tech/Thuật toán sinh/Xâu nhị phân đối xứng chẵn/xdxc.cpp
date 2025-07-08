#include<bits/stdc++.h>
using namespace std;
#define ll long long
set<string> se;
ll n, a[100];
bool check;
void ktao()
{
    for(int i = 1; i <= n; i++) a[i] = 0;
}
void sinh()
{
    int i = n / 2;
    while(i >= 1 && a[i] == 1)
    {
        a[i] = 0;
        i--;
    }
    if(i == 0) check = 0;
    else a[i] = 1;
}
int main()
{
    cin >> n;
    ktao();
    check = 1;
    while(check)
    {
        string s;
        for(int j = 2; j <= n; j += 2)
        {
            for(int i = 1; i <= j / 2; i++) s += to_string(a[i]);
            for(int i = j / 2; i >= 1; i--) s += to_string(a[i]);
            se.insert(s);
            s.clear();
        }
        sinh();
    }
    for(auto x : se) cout << x << endl;
}