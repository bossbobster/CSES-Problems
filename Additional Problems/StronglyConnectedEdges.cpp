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
#pragma GCC optimize("O1,O2,O3,Ofast,unroll-loops")

int n, m;
vector<int> adj[100010];
bitset<100010> vis;
int dep[100010], low[100010];
int cntA = 0;
void dfs(int cur, int d)
{
    if(vis[cur]) return;
    vis[cur] = 1; dep[cur] = d;
    if(low[cur] == -1) low[cur] = dep[cur];
    for(auto it : adj[cur])
    {
        if(dep[it] != max(0, dep[cur]-1))
        {
            if(!vis[it])
            {
                dfs(it, d+1);
                low[cur] = min(low[cur], low[it]);
                if(low[it]-1 >= dep[cur])
                    cntA++;
            }
            else
                low[cur] = min(low[cur], dep[it]);
        }
    }
}
unordered_set<int> don[100010];
void dfs2(int cur)
{
    if(vis[cur]) return;
    vis[cur] = 1;
    for(auto it : adj[cur])
    {
        if(don[cur].count(it)) continue;
        cout << cur+1 << ' ' << it+1 << '\n';
        don[cur].insert(it); don[it].insert(cur);
        dfs2(it);
    }
}
int main()
{
    input();
    int a, b;
    cin >> n >> m;
    for(int i = 0; i < m; i ++)
    {
        cin >> a >> b; a--; b--;
        adj[a].push_back(b); adj[b].push_back(a);
    }
    memset(dep, -1, sizeof(dep)); memset(low, -1, sizeof(low));
    dfs(0, 0);
    if(vis.count() != n || cntA > 0) cout << "IMPOSSIBLE\n";
    vis.reset();
    dfs2(0);
    return 0;
}
