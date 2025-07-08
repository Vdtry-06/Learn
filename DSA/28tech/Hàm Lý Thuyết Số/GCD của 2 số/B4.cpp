#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll LINF= 1e18+5;
const int ING = 1e9;
const int MOD = 1E9+7;
const int MAX = 1e6+5;

int main() 
{
    // freopen("Test1.inp", "r", stdin);
    // freopen("Test1.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) 
    {
        cin >> a[i];
    }
    vector<int> cnt(MAX, 0);
    for (int i = 0; i < n; i++) 
    {
        cnt[a[i]]++;
    }
    int max_gcd = 1;
    for (int i = MAX - 1; i >= 1; i--) 
    {
        int c = 0;
        for(int j = i; j < MAX; j += i)
        {
            c += cnt[j];
            if (c > 1) 
            {
                max_gcd = i;
                break;
            }
        }
        if (max_gcd != 1) break;
    }
    cout << max_gcd << endl;
    return 0;
}
