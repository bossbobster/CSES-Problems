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
typedef pair<int, short> pish;
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
typedef pair<pll, ll> plll;
typedef pair<pll, ld> plld;
typedef pair<int, ll> pil;
typedef pair<ull, ull> pull;
typedef pair<ld, ld> pld;
typedef complex<double> cd;
//#define max(n, m) ((n>m)?n:m)
//#define min(n, m) ((n<m)?n:m)
#define f first
#define s second
#define input() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define eps 1e-9

int n, m;
vector<int> adj[100010];
bitset<100010> vis, back;
int dep[100010], low[100010];
vector<int> ans;
void dfs(int cur, int d)
{
    if(vis[cur]) return;
    vis[cur] = 1; dep[cur] = d;
    if(low[cur] == -1) low[cur] = dep[cur];
    for(auto it : adj[cur])
        if(vis[it])
            low[cur] = min(low[cur], dep[it]);
    bool good = true;
    int cnt = 0;
    for(auto it : adj[cur])
        if(!vis[it])
        {
            dfs(it, d+1);
            low[cur] = min(low[cur], low[it]);
            cnt ++;
            if(low[it] >= dep[cur])
                good = false;
        }
    if(cur == 0) good = true;
    if(cur == 0 && cnt > 1) good = false;
    if(!good)
        ans.push_back(cur);
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
    cout << ans.size() << '\n';
    for(int i = 0; i < ans.size(); i ++)
        cout << ans[i]+1 << ((i==ans.size()-1)?'\n':' ');
}
