#include<bits/stdc++.h>
using namespace std;
#define file() freopen("Test1.inp", "r", stdin); freopen("Test1.out", "w", stdout);
#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FOR(i, l, r) for(int i = l; i <= r; i++)
#define FORD(i, r, l) for(int i = r; i >= l; i--)
#define ll long long
typedef pair<int, pair<int, int>> prr;
typedef pair<int, int> pr;
typedef vector<int> vi;
typedef vector<ll> vll;
#define fi first
#define se second
#define sze size()
#define endl '\n'
const ll LINF= 1e18 + 5;
const int ING = 1e9 + 5;
const int MOD = 1e9 + 7;
const int MAX = 1e6 + 5;
vector<int> v;
stack<int> st;
string s;
int n, p;
void input()
{
    cin >> n;
    // cin.ignore();
    while(n--)
    {
        cin >> s;
        if(s == "push")
        {
            cin >> p;
            st.push(p);
        }
        else if(s == "pop")
        {
            if(!st.empty()) st.pop();
        }
        else if(s == "show")
        {
            if(!st.empty())
            {
                stack<int> tmp = st;
                while(!tmp.empty())
                {
                    v.push_back(tmp.top());
                    tmp.pop();
                }
                reverse(v.begin(), v.end());
                for(int x : v) cout << x << " ";
                v.clear();
                cout << endl; 
            }
            else cout << "EMPTY" << endl;
        }
    }
}
signed main()
{
    // file();
    faster();
    input();
}