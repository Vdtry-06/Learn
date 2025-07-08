#include<bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using ll = long long;
#define file() freopen("Test.inp", "r", stdin); freopen("Test.out", "w", stdout);
#define faster() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pq_min priority_queue<ll, vector<ll>, greater<ll>>
#define pq_max priority_queue<int>
#define pr pair<ll, int>
#define se second
#define fi first
#define endl '\n'
const ll LINF = 1e18 + 5;
const int ING = 1e9 + 5;
const int MOD = 1e9 + 7;
const int MAX = 1e5 + 5;
int degree(char c){
    if(c == '*' || c == '/') return 2;
    return 1;
}
void calculate(stack<int> &st, char c){
    int a = st.top(); st.pop();
    int b = st.top(); st.pop();
    if(c == '*') return st.push(b * a);
    if(c == '/') return st.push(b / a);
    if(c == '+') return st.push(b + a);
    if(c == '-') return st.push(b - a);
}
void process(string s){
    stack<int> st, st1;
    int n = s.size();
    for(int i = 0; i < n; ++i){
        if(isdigit(s[i])){
            int num = 0;
            while(i < n && isdigit(s[i])){
                num = num * 10 + s[i] - '0';
                ++i;
            }
            st.push(num);
            --i;
        }
        else{
            while(!st1.empty() && degree(s[i]) <= degree(st1.top())){
                calculate(st, st1.top());
                st1.pop();
            }
            st1.push(s[i]);
        }
    }
    while(!st1.empty()){
        calculate(st, st1.top());
        st1.pop();
    }
    cout << st.top();
}
void solve(){
    string s;
    cin >> s;
    process(s);
}
signed main() {
    faster();
    // file();
    solve();
}
