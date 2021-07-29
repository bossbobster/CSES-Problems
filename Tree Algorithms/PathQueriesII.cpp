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
#define input() ios_base::sync_with_stdio(0);cin.tie(0);

int n, m, a, b, cnt = 0, type, bitI = 0;
int nums[200010];
vector<int> adj[200010];
int sz[200010];
int chain[200010];
int pars[200010];
int dep[200010];
int bitIdx[200010];
int chainSt[200010];
vector<int> tree[200010];
int chainSz[200010];
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
void dfs1(int cur, int par)
{
    pars[cur] = par;
    for(auto it : adj[cur])
    {
        if(it == par) continue;
        dep[it] = dep[cur]+1;
        dfs1(it, cur);
        sz[cur] += sz[it];
    }
    sz[cur] ++;
}
void dfs2(int cur, int par)
{
    chain[cur] = cnt; chainSz[cnt] ++;
    bitIdx[cur] = bitI++;
    if(adj[cur].size() == 1 && adj[cur][0] == par) return;
    int mx = 200005;
    for(int i = 0; i < adj[cur].size(); i ++)
    {
        if(adj[cur][i] == par) continue;
        if(sz[adj[cur][i]] > sz[mx]) mx = adj[cur][i];
    }
    dfs2(mx, cur);
    for(int i = 0; i < adj[cur].size(); i ++)
    {
        if(adj[cur][i] == par || adj[cur][i] == mx) continue;
        cnt++; chainSt[cnt] = adj[cur][i]; bitI = 0; dfs2(adj[cur][i], cur);
    }
}
int path(int st, int en)
{
    int ans = 0;
    while(chain[st] != chain[en])
    {
        if(dep[chainSt[chain[st]]] > dep[chainSt[chain[en]]]) swap(st, en);
        ans = max(ans, maxQ(chain[en], bitIdx[chainSt[chain[en]]], bitIdx[en]+1));
        en = pars[chainSt[chain[en]]];
    }
    if(bitIdx[st] > bitIdx[en]) swap(st, en);
    ans = max(ans, maxQ(chain[en], bitIdx[st], bitIdx[en]+1));
    return ans;
}
int main()
{
    input();
    cin >> n >> m;
    for(int i = 0; i < n; i ++)
        cin >> nums[i];
    for(int i = 0; i < n-1; i ++)
    {
        cin >> a >> b; a--; b--;
        adj[a].push_back(b); adj[b].push_back(a);
    }
    sz[200005] = -1;
    dfs1(0, -1); dfs2(0, -1);
    for(int i = 0; i <= cnt; i ++)
        tree[i].resize(chainSz[i]*2);
    for(int i = 0; i < n; i ++)
        up(chain[i], bitIdx[i], nums[i]);
    while(m--)
    {
        cin >> type >> a >> b;
        if(type == 1)
        {
            a--;
            up(chain[a], bitIdx[a], b);
            nums[a] = b;
        }
        else
        {
            a--; b--;
            cout << path(a, b) << ((m==0)?"\n":" ");
        }
    }
    return 0;
}
