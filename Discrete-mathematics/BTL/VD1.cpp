#include<bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using ll = long long;
#define file() freopen("test.inp", "r", stdin); freopen("test.out", "w", stdout);
#define faster() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define DIG(d0, d1, d2, d3, d4) (d0 * 10000 + d1 * 1000 + d2 * 100 + d3 * 10 + d4)
#define FORD(i, r, l) for(i = r; i >= l; i--)
#define FOR(i, l, r) for(i = l; i <= r; i++)
#define For(i, l, r) for(i = l; i < r; i++)
#define endl '\n'
const ll LINF= 1e18 + 5;
const int ING = 1e9 + 5;
const int MOD = 1e9 + 7;
const int MAX = 1e6 + 5;
bool check[10000];
int prime[100010];
int a[5][5];
string str[10000];
int cnt, sum;
void sang()
{
    int i, j;
    FOR(i, 10000, 99999)
    {
        FOR(j, 2, sqrt(i))
        {
            if(i % j != 0) continue;
            break;
        }
        if(j * j <= i) continue;
        prime[i] = 1;
    }
}
void matran_5x5()
{
    int i, j;
    For(i, 0, 5)
    {
        For(j, 0, 5) 
        {
            str[cnt].push_back(a[i][j] + '0');
            str[cnt].push_back(' ');
        }
        str[cnt].push_back('\n');
    }
    cnt++;
}
void cot4()
{
    int h0, h1, h2, h3, h4;
    int sum_cr;

    h0 = a[0][4];
    h2 = a[2][4];
    h4 = a[4][4];

    sum_cr = h0 + h2 + h4 + 1; 
    
    for(h1 = 1; h1 < 10 && sum_cr <= sum; h1++, sum_cr++)
    {
        a[1][4] = h1;
        h3 = sum - sum_cr;
        if(h3 > 9 || h3 % 2 == 0) continue; 
        if(!prime[DIG(h0, h1, h2, h3, h4)]) continue;

        a[3][4] = h3; 
        a[1][2] = sum - a[1][0] - a[1][1] - a[1][3] - a[1][4];
        if(a[1][2] > 9 || a[1][2] < 0) continue;
        if(!prime[DIG(a[1][0], a[1][1], a[1][2], a[1][3], a[1][4])]) continue;
        
        a[3][2] = sum - a[3][0] - a[3][1] - a[3][3] - a[3][4]; 
        if(a[3][2] > 9 || a[3][2] < 0) continue;
        if(!prime[DIG(a[3][0], a[3][1], a[3][2], a[3][3], a[3][4])]) continue;

        if(a[0][2] + a[1][2] + a[2][2] + a[3][2] + a[4][2] != sum) continue;
        if(!prime[DIG(a[0][2], a[1][2], a[2][2], a[3][2], a[4][2])]) continue;
        
        matran_5x5();
    }
}
void cot0()
{
    
    int h0, h1, h2, h3, h4;
    int sum_cr;

    h0 = a[0][0];
    h2 = a[2][0];
    h4 = a[4][0];

    sum_cr = h0 + h2 + h4 + 1;

    for(h1 = 1; h1 < 10 && sum_cr <= sum; h1++, sum_cr++)
    {
        a[1][0] = h1;
        h3 = sum - sum_cr;
        if(h3 > 9) continue; 
        if(!prime[DIG(h0, h1, h2, h3, h4)]) continue;
        a[3][0] = h3; 

        cot4();
    }
}

void hang2()
{
    int c0, c1, c2, c3, c4;
    int sum_cr;

    c1 = a[2][1];
    c2 = a[2][2];
    c3 = a[2][3];

    sum_cr = c1 + c2 + c3 + 1;

    for(c0 = 1; c0 < 10 && sum_cr <= sum; c0++, sum_cr++)
    {
        a[2][0] = c0;
        c4 = sum - sum_cr;
        if(c4 > 9 || c4 % 2 == 0) continue;
        if(!prime[DIG(c0, c1, c2, c3, c4)]) continue;
        a[2][4] = c4;

        cot0();
    }
}
void cot3()
{
    int h0, h1, h2, h3, h4;
    int sum_cr;

    h1 = a[1][3];
    h3 = a[3][3];
    h4 = a[4][3];

    sum_cr = h1 + h3 + h4 + 1;

    for(h0 = 1; h0 < 10 && sum_cr <= sum; h0++, sum_cr++)
    {
        a[0][3] = h0;
        h2 = sum - sum_cr;
        if(h2 > 9) continue;
        if(!prime[DIG(h0, h1, h2, h3, h4)]) continue;

        a[2][3] = h2;
        a[0][2] = sum - a[0][0] - a[0][1] - a[0][3] - a[0][4];
        if(a[0][2] > 9 || a[0][2] < 0) continue;
        if(!prime[DIG(a[0][0], a[0][1], a[0][2], a[0][3], a[0][4])]) continue;

        hang2();
    }
}
void hang4()
{
    int c0,c1,c2,c3,c4;
    int sum_cr;

    c0 = a[4][0];
    c1 = a[4][1];
    c4 = a[4][4];

    sum_cr = c0 + c1 + c4;

    for(c2 = 0; c2 < 10 && sum_cr <= sum; c2++, sum_cr++)
    {
        a[4][2] = c2;
        c3 = sum - sum_cr;
        if(c3 > 9 || c3 % 2 == 0) continue;
        if(!prime[DIG(c0, c1, c2, c3, c4)]) continue;

        a[4][3] = c3;

        cot3();
    }
}
void cot1()
{
    int h0, h1, h2, h3, h4;
    int sum_cr;

    h1 = a[1][1];
    h3 = a[3][1];
    sum_cr = h1 + h3 + 1;

    for(h0 = 1; h0 < 10 && sum_cr <= sum; h0++ , sum_cr++)
    {

        a[0][1] = h0;
        for(h2 = 0; h2 < 10 && sum_cr <= sum; h2++, sum_cr++)
        {
            a[2][1] = h2;
            h4 = sum - sum_cr;
            if(h4 > 9) continue;
            if(!prime[DIG(h0, h1, h2, h3, h4)]) continue;

            a[4][1] = h4;
            hang4();
        }
        sum_cr -= h2;
    }
}
void duong_cheo_phu()
{
    int d0, d1, d2, d3, d4;
    int sum_cr;

    d2 = a[2][2];
    sum_cr = d2 + 1;
    for(d0 = 1; d0 < 10 && sum_cr <= sum; d0++, sum_cr++)
    {
        a[4][0] = d0;
        for(d1 = 0; d1 < 10 && sum_cr <= sum; d1++, sum_cr++)
        {
            a[3][1] = d1;
            for(d3 = 0; d3 < 10 && sum_cr <= sum; d3++, sum_cr++)
            {

                a[1][3] = d3;
                d4 = sum - sum_cr;
                if(d4 > 9) continue;
                if(!prime[DIG(d0, d1, d2, d3, d4)]) continue;
                a[0][4] = d4;

                cot1();
            }
            sum_cr -= d3;
        }
        sum_cr -= d1;
    }
}
void duong_cheo_chinh()
{
    int d0, d1, d2, d3, d4;
    int sum_cr;

    d0 = a[0][0];
    sum_cr = d0;

    for(d1 = 0; d1 < 10 && sum_cr <= sum; d1++, sum_cr++)
    {
        a[1][1] = d1;
        for(d2 = 0; d2 < 10 && sum_cr <= sum; d2++, sum_cr++)
        {
            a[2][2] = d2;
            for(d3 = 0; d3 < 10 && sum_cr <= sum; d3++, sum_cr++)
            {
                a[3][3] = d3;
                d4 = sum - sum_cr;
                if(d4 > 9) continue;
                if(!prime[DIG(d0, d1, d2, d3, d4)]) continue;
                a[4][4] = d4;

                duong_cheo_phu();
            }
            sum_cr -= d3;
        }
        sum_cr -= d2;
    }
}
void solve()
{
    
    vector<string> v;
    cin >> sum;
    int d = 0, i, j;
    memset(check, false, sizeof(check));
    For(j, 1, 10)
    {
        a[0][0] = j;
        sang();
        duong_cheo_chinh();
        sort(str, str + cnt);
        For(i, 0, cnt)
        {
            if(!check[i])
            {
                check[i] = true;
                d++;
                v.push_back(str[i]);
            }
        }
    }
    cout << "so cau hinh thoa man la: ";
    cout << d << endl;
    For(i, 0, v.size())
    {
        cout << v[i] << endl;
    }
}
signed main()
{
    file();
    cout << "nhap tong cac chu so: ";
    faster();
    solve();
}

