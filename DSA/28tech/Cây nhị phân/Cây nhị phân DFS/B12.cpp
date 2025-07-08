#include<bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using ll = long long;
#define file() freopen("Test2.inp", "r", stdin); freopen("Test2.out", "w", stdout);
#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FORD(i, r, l) for(int i = r; i >= l; i--)
#define FOR(i, l, r) for(int i = l; i < r; i++)
typedef priority_queue<int, vector<int>, greater<int>> pq_min;
typedef pair<int, pair<int, int>> prr;
typedef priority_queue<ll> pq_max;
typedef pair<int, int> pr;
typedef vector<int> vi;
typedef vector<ll> vll;
const ll LINF= 1e18 + 5;
const int ING = 1e9 + 5;
const int MOD = 1e9 + 7;
const int MAX = 1e6 + 5;
#define fi first 
#define se second
#define sze size()
#define endl '\n'
struct node
{
    int data;
    node *left, *right;
    node(int x)
    {
        data = x;
        left = right = NULL;
    } 
};
void makenode(node *root, int x, int y, char z)
{
    if(z == 'L') root->left = new node(y);
    else root->right = new node(y);
}
void insert(node *root, int x, int y, char z)
{
    if(root == NULL) return;
    if(root->data == x) makenode(root, x, y, z);
    else
    {
        insert(root->left, x, y, z);
        insert(root->right, x, y, z);
    }
}
vector<int> v;
void dfs(node *root)
{
    if(root == NULL) return;
    cout << root->data << " ";
    dfs(root->right);
    dfs(root->left);
}
void input()
{
    node *root;
    root = NULL;
    int n; cin >> n;
    FOR(i, 0, n)
    {
        int x, y; char z;
        cin >> x >> y >> z;
        if(!root) 
        {
            root = new node(x);
            makenode(root, x, y, z);
        }
        else insert(root, x, y, z);
    }
    dfs(root);
}
signed main()
{
    // file();
    faster();
    input();
}
