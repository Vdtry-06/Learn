#include<bits/stdc++.h>
#define fr(i, l, r) for(int i = l; i < r; i++)
#define fr1(i, r, l) for(int i = r - 1; i >= l; i--)
#define pr pair<int, int>
#define fi first
#define se second
using namespace std;
using ll = long long;
const ll LINF= 1e18 + 5;
const int ING = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 1e6 + 5;
vector<string> v;
stack<pr> st;
string s;
int k;
void eat()
{
    cin >> s >> k;
}
void sleep()
{
    fr(i, 0, s.size()) 
    {
        if(!st.empty() && st.top().fi == s[i]) 
        {
            st.top().se++;
            if(st.top().se == k) st.pop();
        }
        else st.push({s[i], 1});
    }
    if(st.empty()) cout << "EMPTY";
    else
    {
        string tmp = "";
        while(!st.empty())
        {
            tmp = string(st.top().se, st.top().fi) + tmp;st.pop();
        }
        cout << tmp;
    }
    
}
signed main()
{
    // freopen("Test1.inp", "r", stdin);
    // freopen("Test1.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    eat();
    sleep();
}
