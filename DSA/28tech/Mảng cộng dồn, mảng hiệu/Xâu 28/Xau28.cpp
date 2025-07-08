#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MAX = 1e6 + 5;
string s;
ll x, y;
int main()
{
    cin >> s >> x >> y;
    ll l = 0, r = 0, cnt2 = 0, cnt8 = 0, mx = -1e9;
    while(r < s.size())
    {
        if(s[r] == '2') cnt2++;
        else cnt8++;
        while(cnt2 > x || cnt8 > y)
        {
            if(s[l] == '2') cnt2--;
            else cnt8--;
            l++;
        }
        mx = max(mx, r - l + 1);
        r++;
    }
    cout << mx;
}