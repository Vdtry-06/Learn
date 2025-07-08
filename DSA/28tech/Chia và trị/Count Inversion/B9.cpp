#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll LINF= 1e18+5;
const int ING = 1e9;
const int MOD = 1e9+7;
const int MAX = 1e6+5;
ll merge(int a[], int l, int m, int r)
{
    vector<int> a1(a + l, a + m + 1);
    vector<int> a2(a + m + 1, a + r + 1);
    int i = 0, j = 0, k = l;
    ll cnt = 0;
    while(i < a1.size() && j < a2.size())
    {
        if(a1[i] <= a2[j]) a[k++] = a1[i++];
        else 
        {
            a[k++] = a2[j++];
            cnt += a1.size() - i;
        }
    }
    while(i < a1.size()) a[k++] = a1[i++];
    while(j < a2.size()) a[k++] = a2[j++];
    return cnt;
}
ll mergesort(int a[], int l, int r)
{
    if(l == r) return 0;
    int m = (l + r) / 2;
    return mergesort(a, l, m) + mergesort(a, m + 1, r) + merge(a, l, m, r);
}
int main()
{
    // freopen("Test1.inp", "r", stdin);
    // freopen("Test1.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int a[n];
    for(int &x : a) cin >> x;
    cout << mergesort(a, 0, n - 1);
    
}