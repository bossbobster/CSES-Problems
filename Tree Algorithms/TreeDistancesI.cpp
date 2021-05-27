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

int n;
vector<int> adj[200010];
int mx1[200010], mx2[200010], ans[200010], up[200010];
void dfs(int cur, int par)
{
    for(auto it : adj[cur])
    {
        if(it == par) continue;
        dfs(it, cur);
        if(mx1[it]+1 > mx1[cur]) { mx2[cur] = mx1[cur]; mx1[cur] = mx1[it]+1; }
        else if(mx1[it]+1 > mx2[cur]) mx2[cur] = mx1[it]+1;
    }
}
void dfs2(int cur, int par)
{
    if(cur == 0) { ans[cur] = mx1[cur]; }
    else
    {
        if(mx1[par] == mx1[cur]+1)
        {
            ans[cur] = max({mx1[cur], mx2[par]+1, up[par]+1});
            up[cur] = max(mx2[par]+1, up[par]+1);
        }
        else
        {
            ans[cur] = max({mx1[cur], mx1[par]+1, up[par]+1});
            up[cur] = max(mx1[par]+1, up[par]+1);
        }
    }
    for(auto it : adj[cur])
        if(it != par)
            dfs2(it, cur);
}
int main()
{
    input();
    int a, b;
    cin >> n;
    for(int i = 0; i < n-1; i ++)
    {
        cin >> a >> b; a--; b--;
        adj[a].push_back(b); adj[b].push_back(a);
    }
    dfs(0, -1); dfs2(0, -1);
    for(int i = 0; i < n; i ++)
        cout << ans[i] << " ";
    cout << "\n";
}
