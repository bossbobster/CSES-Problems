#include <iostream>
#include <string.h>
#include <random>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <array>
#include <bitset>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <complex>
#include <valarray>
#include <memory>
#include <cassert>
#include <chrono>
using namespace std;
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
typedef pair<int, int> pii;
typedef pair<int, string> pis;
typedef pair<pis, string> piss;
typedef pair<int, short> pish;
typedef pair<string, string> pss;
typedef pair<int, char> pic;
typedef pair<pii, int> piii;
typedef pair<double, double> pdd;
typedef pair<double, int> pdi;
typedef pair<float, float> pff;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef unsigned short ushort;
typedef pair<uint, uint> puint;
typedef pair<ll, ll> pll;
typedef pair<pll, ll> plll;
typedef pair<pll, ld> plld;
typedef pair<ld, int> pldi;
typedef pair<int, ll> pil;
typedef pair<ll, int> pli;
typedef pair<ull, ull> pull;
typedef pair<ld, ld> pld;
typedef complex<double> cd;
//#define max(n, m) ((n>m)?n:m)
//#define min(n, m) ((n<m)?n:m)
#define f first
#define s second
#define input() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
//#define eps 1e-8
//#define eps2 1e-15
#define leni(x) sizeof(x)/sizeof(int)
#define v(i,j,k) for(i=j;i<k;i++)
//#define cin fin
//#define cout fout
//#define fin cin
//#define fout cout
#pragma GCC optimize("O1,O2,O3,Ofast,unroll-loops")

int n, k1, k2, a, b, root;
int sz[200010];
vector<int> adj[200010];
int p[200010];
bitset<200010> vis;
int bit[200010];
int mx;
int sum(int idx)
{
    int ans = 0;
    idx ++;
    while(idx > 0)
    {
        ans += bit[idx];
        idx -= idx & (-idx);
    }
    return ans;
}
void update(int idx, int val)
{
    idx ++;
    while(idx <= mx+1)
    {
        bit[idx] += val;
        idx += idx & (-idx);
    }
}
int dfs1(int cur, int par)
{
    sz[cur] = 1;
    for(auto nx : adj[cur])
        if(nx != par && !vis[nx])
            sz[cur] += dfs1(nx, cur);
    return sz[cur];
}
int dfs2(int cur, int par, int n)
{
    for(auto nx : adj[cur])
        if(nx != par && sz[nx] > n/2 && !vis[nx])
            return dfs2(nx, cur, n);
    return cur;
}
ll ans = 0;
void dfs21(int cur, int par, int d)
{
    if(d > k2) return;
    mx = max(mx, d);
    for(auto nx : adj[cur])
        if(nx != par && !vis[nx])
            dfs21(nx, cur, d+1);
}
int mxU = 0;
void dfs3(int cur, int par, int d)
{
    if(d > k2) return;
    if(mxU >= k1-d)
        ans += sum(min(mx, k2-d)) - sum(min(mx, k1-d-1));
    for(auto nx : adj[cur])
        if(nx != par && !vis[nx])
            dfs3(nx, cur, d+1);
}
void dfs4(int cur, int par, int d)
{
    if(d > k2) return;
    update(d, 1);
    mxU = max(mxU, d);
    for(auto nx : adj[cur])
        if(nx != par && !vis[nx])
            dfs4(nx, cur, d+1);
}
void make(int cur, int par)
{
    int cent = dfs2(cur, par, dfs1(cur, par));
    vis[cent] = 1;
    mx = 0;
    for(auto it : adj[cent])
        if(!vis[it])
            dfs21(it, cent, 1);
    if(mx*2 >= k1)
    {
        mxU = 0;
        for(auto it : adj[cent])
            if(!vis[it])
                dfs3(it, cent, 1), dfs4(it, cent, 1);
        ans += sum(mx) - sum(min(mx, k1-1));
        for(int i = 0; i <= mx; i ++)
        {
            int num = 0;
            if((i+1)%2 == 1) num = bit[i+1];
            else if((i+1)%4 == 2) num = bit[i+1]-bit[(i+1)/2];
            else num = sum(i)-sum(i-1);
            if(num != 0)
                update(i, -num);
        }
    }
    else return;
    for(auto it : adj[cent])
        if(!vis[it])
            make(it, cent);
}
ll solve(int a, int b)
{
    if(a > b) return 0;
    k1 = a; k2 = b;
    ans = 0;
    vis.reset();
    memset(bit, 0, sizeof(bit));
    make(0, -1);
    return ans;
}
int main()
{
    input();
    int K1, K2;
    cin >> n >> K1 >> K2;
    for(int i = 0; i < n-1; i ++)
    {
        cin >> a >> b; a--; b--;
        adj[a].push_back(b); adj[b].push_back(a);
    }
    if(K2-K1 > n/2)
    {
        ll big = (ll)n*(ll)(n-1)/2;
        big -= solve(1, K1-1)+solve(K2+1, n);
        cout << big << '\n';
    }
    else
        cout << solve(K1, K2) << '\n';
    return 0;
}
