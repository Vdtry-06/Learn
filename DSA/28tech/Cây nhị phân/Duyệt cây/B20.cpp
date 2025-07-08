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
    node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

int poa[105], ioa[105], n;
int find(int a[], int x)
{
    FOR(i, 0, n)
    {
        if(a[i] == x) return i;
    }
    return -1;
}
void buildtree(node *root, int in_left, int in_right)
{
    int in_root_pos = find(ioa, root->data);
    int pre_root_pos = find(poa, root->data);
    if(in_root_pos > in_left)
    {
        int left_value = poa[pre_root_pos + 1];
        root->left = new node(left_value);
        buildtree(root->left, in_left, in_root_pos - 1);
    }
    if(in_root_pos < in_right)
    {
        int left_size = in_root_pos - in_left;
        int right_value = poa[pre_root_pos + left_size + 1];
        root->right = new node(right_value);
        buildtree(root->right, in_root_pos + 1, in_right);
    }
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
    cin >> n;
    FOR(i, 0, n) cin >> poa[i];
    FOR(i, 0, n) cin >> ioa[i];
    node *root = new node(poa[0]);
    buildtree(root, 0, n - 1);
    postorder(root);
}
signed main()
{
    // file();
    faster();
    input();
}
