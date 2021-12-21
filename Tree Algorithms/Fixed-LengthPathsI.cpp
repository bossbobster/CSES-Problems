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
using namespace std;
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//template <class T> using Tree = tree<T, null_type, less<T>,
//rb_tree_tag, tree_order_statistics_node_update>;
typedef pair<int, int> pii;
typedef pair<int, string> pis;
typedef pair<string, string> pss;
typedef pair<int, char> pic;
typedef pair<pii, int> piii;
typedef pair<double, double> pdd;
typedef pair<float, float> pff;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<ll, ll> pll;
typedef pair<int, ll> pil;
typedef pair<ull, ull> pull;
typedef pair<ld, ld> pld;
typedef complex<double> cd;
//#define max(n, m) ((n>m)?n:m)
//#define min(n, m) ((n<m)?n:m)
#define f first
#define s second
#define input() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int n, k, a, b, root;
int sz[200010];
vector<int> adj[200010];
int p[200010];
bitset<200010> vis;
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
int mx;
ll ans = 0;
int cnt[200010];
void dfs3(int cur, int par, int d)
{
    if(d > k) return;
    mx = max(mx, d);
    ans += cnt[k-d];
    for(auto nx : adj[cur])
        if(nx != par && !vis[nx])
            dfs3(nx, cur, d+1);
}
void dfs4(int cur, int par, int d)
{
    if(d > k) return;
    mx = max(mx, d);
    cnt[d]++;
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
            dfs3(it, cent, 1), dfs4(it, cent, 1);
    ans += cnt[k];
    fill(cnt, cnt+mx+5, 0);
    for(auto it : adj[cent])
        if(!vis[it])
            make(it, cent);
}
int main()
{
    input();
    cin >> n >> k;
    for(int i = 0; i < n-1; i ++)
    {
        cin >> a >> b; a--; b--;
        adj[a].push_back(b); adj[b].push_back(a);
    }
    make(0, -1);
    cout << ans << '\n';
    return 0;
}
