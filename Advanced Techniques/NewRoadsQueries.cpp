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
#include <bitset>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <complex>
#include <valarray>
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
using namespace std;
typedef pair<int, int> pii;
typedef pair<int, string> pis;
typedef pair<string, string> pss;
typedef pair<int, char> pic;
typedef pair<pii, int> piii;
typedef pair<double, double> pdd;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<ll, ll> pll;
typedef pair<int, ll> pil;
typedef pair<ull, ull> pull;
typedef complex<double> cd;
//#define max(n, m) ((n>m)?n:m)
//#define min(n, m) ((n<m)?n:m)
#define f first
#define s second
#define input() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

struct dsu
{
    // parent array
    int par[400010];
    // size array
    int size[400010];
    // constructor
    dsu(int s)
    {
        for(int i = 0; i <= s; i ++)
        {
            par[i] = i; size[i] = 1;
        }
    }
    // find root of n
    int root(int n)
    {
        if(par[n] == n || par[n] == -1)
            return n;
        return par[n] = root(par[n]);
    }
    // return true if n and m are in the same CC
    bool con(int n, int m)
    {
        return (root(n) == root(m));
    }
    // connect n and m
    void un(int n, int m)
    {
        n = root(n); m = root(m);
        if(n == m) return;
        if(size[n] < size[m])
            swap(n, m);
        par[m] = n;
        size[n] += size[m];
    }
};
int n, m, q, a, b, cnt = 0, bitI = 0;
vector<pii> adj[400010];
int sz[400010];
int chain[400010];
int pars[400010];
int dep[400010];
int bitIdx[400010];
int chainSt[400010];
vector<int> tree[400010];
int chainSz[400010];
int cst[400010];
bitset<400010> visited;
void up(int which, int idx, int val)
{
    tree[which][idx + chainSz[which]] = val;
    idx += chainSz[which];
    for(int i = idx; i > 1; i >>= 1)
        tree[which][i >> 1] = max(tree[which][i], tree[which][i ^ 1]);
}
int maxQ(int which, int l, int r) // inclusive l, exclusive r
{
    int ans = 0;
    for(l += chainSz[which], r += chainSz[which]; l < r; l >>= 1, r >>= 1)
    {
        if(l & 1)
            ans = max(ans, tree[which][l ++]);
        if(r & 1)
            ans = max(ans, tree[which][-- r]);
    }
    return ans;
}
void dfs1(int cur, int par, int cost)
{
    visited[cur] = 1;
    pars[cur] = par; cst[cur] = cost;
    for(auto it : adj[cur])
    {
        if(it.f == par) continue;
        dep[it.f] = dep[cur]+1;
        dfs1(it.f, cur, it.s);
        sz[cur] += sz[it.f];
    }
    sz[cur] ++;
}
void dfs2(int cur, int par)
{
    chain[cur] = cnt; chainSz[cnt] ++;
    bitIdx[cur] = bitI++;
    if(adj[cur].size() == 0 || (adj[cur].size() == 1 && adj[cur][0].f == par)) return;
    int mx = 200005;
    for(int i = 0; i < adj[cur].size(); i ++)
    {
        if(adj[cur][i].f == par) continue;
        if(sz[adj[cur][i].f] > sz[mx]) mx = adj[cur][i].f;
    }
    dfs2(mx, cur);
    for(int i = 0; i < adj[cur].size(); i ++)
    {
        if(adj[cur][i].f == par || adj[cur][i].f == mx) continue;
        cnt++; chainSt[cnt] = adj[cur][i].f; bitI = 0; dfs2(adj[cur][i].f, cur);
    }
}
int path(int st, int en)
{
    int ans = 0;
    while(chain[st] != chain[en])
    {
        if(dep[chainSt[chain[st]]] > dep[chainSt[chain[en]]]) swap(st, en);
        ans = max({ans, maxQ(chain[en], bitIdx[chainSt[chain[en]]], bitIdx[en]+1), cst[chainSt[chain[en]]]});
        en = pars[chainSt[chain[en]]];
    }
    if(bitIdx[st] > bitIdx[en]) swap(st, en);
    ans = max(ans, maxQ(chain[en], bitIdx[st]+1, bitIdx[en]+1));
    return ans;
}
int main()
{
    input();
    cin >> n >> m >> q;
    dsu d = dsu(n);
    for(int i = 0; i < m; i ++)
    {
        cin >> a >> b; a--; b--;
        if(!d.con(a, b))
        {
            d.un(a, b);
            adj[a].push_back({b, i+1}); adj[b].push_back({a, i+1});
        }
    }
    sz[200005] = -1;
    for(int i = 0; i < n; i ++)
        pars[i] = -1;
    for(int i = 0; i < n; i ++)
    {
        if(visited[i]) continue;
        cnt++; chainSt[cnt] = i; bitI = 0;
        dfs1(i, -1, 0); dfs2(i, -1);
    }
    for(int i = 0; i <= cnt; i ++)
        tree[i].resize(chainSz[i]*2+1);
    for(int i = 0; i < n; i ++)
        if(pars[i] != -1 && chain[i] == chain[pars[i]])
            up(chain[i], bitIdx[i], cst[i]);
    while(q--)
    {
        cin >> a >> b; a--; b--;
        if(!d.con(a, b)) cout << "-1\n";
        else cout << path(a, b) << "\n";
    }
}
