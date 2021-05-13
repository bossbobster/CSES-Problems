#include <iostream>
#include <string.h>
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
#pragma GCC optimize ("O2")
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
using namespace std;
typedef pair<int, int> pii;
typedef pair<int, string> pis;
typedef pair<int, char> pic;
typedef pair<pii, int> piii;
typedef pair<double, double> pdd;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<ll, ll> pll;
typedef pair<int, ll> pil;
typedef pair<ull, ull> pull;
//#define max(n, m) ((n>m)?n:m)
//#define min(n, m) ((n<m)?n:m)
#define f first
#define s second
#define input() ios_base::sync_with_stdio(0);cin.tie(0);

int n, q, a, b, type;
ll nums[200010];
vector<int> adj[200010];
int lca[200010][20];
int size[200010];
int dep[200010];
ll seg[800010];
int ogToSeg[200010];
int top[200010];
void segUpdate(int cur, int l, int r, int idx, int val)
{
    if(l == r) seg[cur] = val;
    else
    {
        int mid = (l + r) / 2;
        if(idx <= mid) segUpdate(cur * 2, l, mid, idx, val);
        else segUpdate(cur * 2 + 1, mid + 1, r, idx, val);
        seg[cur] = seg[cur * 2] + seg[cur * 2 + 1];
    }
}
void up(int idx, int val) { return segUpdate(1, 0, n - 1, idx, val); }
ll segMx(int cur, int l, int r, int lq, int rq)
{
    if(l >= lq && r <= rq) return seg[cur];
    int mid = (l + r) / 2; ll ans = 0;
    if(mid >= lq) ans += segMx(cur * 2, l, mid, lq, rq);
    if(mid + 1 <= rq) ans += segMx(cur * 2 + 1, mid + 1, r, lq, rq);
    return ans;
}
ll mx(int lq, int rq) { return segMx(1, 0, n - 1, lq, rq); }
int LCA(int a, int b)
{
    if(dep[b] > dep[a]) swap(a, b);
    for(int i = 19; i >= 0; i --)
        if(dep[a] - (1 << i) >= dep[b])
            a = lca[a][i];
    for(int i = 19; i >= 0; i --)
        if(lca[a][i] != lca[b][i])
        {
            a = lca[a][i]; b = lca[b][i];
        }
    if(a != b)
        a = lca[a][0];
    return a;
}
void dfs(int cur, int par)
{
    size[cur] ++;
    for(int other : adj[cur])
    {
        if(other == par) continue;
        dep[other] = dep[cur] + 1;
        lca[other][0] = cur;
        dfs(other, cur);
        size[cur] += size[other];
    }
}
void dfsHLD(int cur, int topIdx, int par, int &idx)
{
    ogToSeg[cur] = idx; idx ++;
    up(ogToSeg[cur], nums[cur]);
    top[cur] = topIdx;
    int maxN = -1, maxIdx = -1;
    for(int other : adj[cur])
    {
        if(other == par) continue;
        if(size[other] > maxN)
        {
            maxN = size[other];
            maxIdx = other;
        }
    }
    if(maxIdx < 0) return;
    dfsHLD(maxIdx, topIdx, cur, idx);
    for(int other : adj[cur])
        if(other != par && other != maxIdx)
            dfsHLD(other, other, cur, idx);
}
ll pathUtil(int cur, int par)
{
    ll ans = 0;
    while(cur != par)
    {
        if(top[cur] == cur)
        {
            ans += nums[cur];
            cur = lca[cur][0];
        }
        else if(dep[top[cur]] > dep[par])
        {
            ans += mx(ogToSeg[top[cur]], ogToSeg[cur]);
            cur = lca[top[cur]][0];
        }
        else
        {
            ans += mx(ogToSeg[par] + 1, ogToSeg[cur]);
            break;
        }
    }
    return ans;
}
ll path(int a, int b)
{
    int lcaAB = LCA(a, b);
    return pathUtil(a, lcaAB) + pathUtil(b, lcaAB) + nums[lcaAB];
}
int main()
{
    input();
    cin >> n >> q;
    for(int i = 0; i < n; i ++)
        cin >> nums[i];
    for(int i = 0; i < n-1; i ++)
    {
        cin >> a >> b; a --; b --;
        adj[a].push_back(b); adj[b].push_back(a);
    }
    dfs(0, -1);
    for(int i = 1; i < 20; i ++)
        for(int j = 0; j < n; j ++)
            lca[j][i] = lca[lca[j][i - 1]][i - 1];
    int idx = 0;
    dfsHLD(0, 0, -1, idx);
    while(q--)
    {
        cin >> type >> a; a--;
        if(type == 1)
        {
            cin >> b;
            nums[a] = b;
            up(ogToSeg[a], b);
        }
        else
            cout << path(0, a) << "\n";
    }
}
