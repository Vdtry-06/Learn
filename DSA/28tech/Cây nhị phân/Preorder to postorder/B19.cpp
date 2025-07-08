#include<bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using ll = long long;
#define file() freopen("Test2.inp", "r", stdin); freopen("Test2.out", "w", stdout);
#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pq_min priority_queue<int, vector<int>, greater<int>> 
#define pq_max priority_queue<int> 
#define FORD(i, r, l) for(int i = r; i >= l; i--)
#define FOR(i, l, r) for(int i = l; i < r; i++)
#define all(x) x.begin(), x.end()
#define pr pair<int, int>
#define prr pair<int, pr> 
#define fi first 
#define se second
#define sze size()
#define endl '\n'
const ll LINF= 1e18 + 5;
const int ING = 1e9 + 5;
const int MOD = 1e9 + 7;
const int MAX = 1e6 + 5;

struct node
{
    int data;
    node *left, *right;
};
node *makenode(int x)
{
    node *n_n = new node;
    n_n->data = x;
    n_n->left = NULL;
    n_n->right = NULL;
    return n_n;
}
node *insert(node *root, int key)
{
    if(root == NULL) return makenode(key);
    if(key < root->data)
    {
        root->left = insert(root->left, key);
    }
    else if(key > root->data)
    {
        root->right = insert(root->right, key);
    }
    return root;
}
void postorder(node *root)
{
    if(root == NULL) return;
    postorder(root->left);   
    postorder(root->right);
    cout << root->data << " ";
}

void input()
{
    node *root = NULL;
    int n; cin >> n;
    FOR(i, 0, n)
    {
        int x; cin >> x;
        if(!root) root = makenode(x);
        else insert(root, x);
    }
    postorder(root);
}
signed main()
{
    // file();
    faster();
    input();
}
