#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll check(ll n)
{
    for(int i=0;i<=n/111;i++)
    {
        int tmp=n-111*i;
        if(tmp%11==0) return 1;
    }
    return 0;
}
int main()
{
    ll n;
    cin>>n;
    if(check(n)) cout<<"YES";
    else cout<<"NO";
}
