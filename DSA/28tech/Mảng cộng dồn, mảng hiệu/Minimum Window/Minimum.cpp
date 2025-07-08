#include<bits/stdc++.h>
using namespace std;
#define ll long long
string s, t;
map<char, ll> mp;
int main()
{
    cin >> s >> t;
    for(auto x : t) mp[x]++;
    ll cnt = mp.size();
    ll l = 0, vtd = 0, vtc = 0, mi = INT_MAX;
    for(int i = 0; i < s.size(); i++)
    {
        if(mp.find(s[i]) != mp.end())
        {
            mp[s[i]]--;
            if(mp[s[i]] == 0) cnt--;
        }
        while(cnt == 0)
        {
            if(mi > i - l + 1)
            {
                mi = i - l + 1;
                vtd = l;
                vtc = i;
            }
            if(mp.find(s[l]) != mp.end())
            {
                mp[s[l]]++;
                if(mp[s[l]] == 1) cnt++;
            }
            l++;
        }
    }
    if(mi == INT_MAX) cout << -1;
    else
    {
        for(int i = vtd; i <= vtc; i++) cout << s[i];
    }
}
