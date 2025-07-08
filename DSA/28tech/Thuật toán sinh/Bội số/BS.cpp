#include<bits/stdc++.h>
#define ll long long
using namespace std;

int n, a[1000];
vector<ll> v;
bool check;

void sinh()
{
    int i = n;
    while(i >= 1 && a[i] == 8) 
    {
        a[i] = 0;
        i--;
    }
    if(i == 0) check = 0;
    else a[i] = 8;
}

int main()
{
    n = 19;
    a[n] = 8;
    check = 1;
    while(check)
    {
        ll s = 0;
        for(int i = 1; i <= n; i++) 
        {
            s = s * 10 + a[i];
        }
        v.push_back(s);
        sinh();
    }
    int t;
    cin >> t;
    while(t--)
    {
        int q;
        cin >> q;
        for(auto x : v)
        {
            if(x % q == 0)
            {
                cout << x << endl; 
                break;
            }
        }
    }
}
