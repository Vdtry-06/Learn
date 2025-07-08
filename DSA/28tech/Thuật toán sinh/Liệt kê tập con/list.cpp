#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;
const ll LINF= 1e18 + 5;
const int ING = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 1e6 + 5;

int n, k, a[1000], ok;

void ktao()
{
    for(int i = 1; i <= n; i++)
    { 
        a[i] = 0;
    }
    a[n] = 1;
}

void sinh()
{
    int i = n;
    while(i >= 1 && a[i] == 1) i--;
    if(i == 0) ok = 0;
    else
    {
        a[i] = 1;
        for(int j = i + 1; j <= n; j++)
        {
            a[j] = 0;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    ok = 1;
    ktao();
    vector<string> v;
    while(ok)
    {
        string s = "";
        for(int i = 1; i <= n; i++)
        {
            if(a[i]) 
            {
                s += to_string(i);
                s += ' ';
            }
        }
        v.push_back(s);
        sinh();
    }
    sort(v.begin(), v.end());
    for(auto x : v) cout << x << endl;
}