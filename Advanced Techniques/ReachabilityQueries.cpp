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
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
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

struct chash { /// use most bits rather than just the lowest ones
    const uint64_t C = ll(2e18*(3.14))+71; // large odd number
    const int RANDOM = rand(); // random 32-bit number
    ll operator()(ll x) const {
        // https://gcc.gnu.org/onlinedocs/gcc/Other-Builtins.html
        return __builtin_bswap64((x^RANDOM)*C);
    }
};
 
vector<int> adj[50010];
vector<int> rev[50010];
gp_hash_table<int, null_type, chash> rev2[50010];
int in[50010];
bool visited[50010];
int scc[50010];
stack<int> ord;
queue<int> qq;
int curCC = 1;
bitset<50010> all[50010];
void dfs1(int cur)
{
    visited[cur] = true;
    for(auto it : adj[cur])
    {
        if(visited[it]) continue;
        dfs1(it);
    }
    ord.push(cur);
}
void dfs2(int cur)
{
    scc[cur] = curCC;
    for(auto it : rev[cur])
    {
        if(scc[it]) continue;
        dfs2(it);
    }
}
int main()
{
    input();
    int n, m, q, a, b, cur;
    cin >> n >> m >> q;
    for(int i = 0; i < m; i ++)
    {
        cin >> a >> b; a--; b--;
        adj[a].push_back(b); rev[b].push_back(a);
    }
    memset(visited, false, sizeof(visited));
    for(int i = 0; i < n; i ++)
        if(!visited[i])
            dfs1(i);
    memset(scc, 0, sizeof(scc));
    while(!ord.empty())
    {
        if(!scc[ord.top()])
        {
            dfs2(ord.top());
            curCC ++;
        }
        ord.pop();
    }
    for(int i = 0; i < n; i ++)
        for(auto it : rev[i])
        {
            if(scc[it] != scc[i])
            {
                if(rev2[scc[i]].find(scc[it]) == rev2[scc[i]].end()) in[scc[it]] ++;
                rev2[scc[i]].insert(scc[it]);
            }
        }
    for(int i = 1; i < curCC; i ++)
    {
        all[i][i] = 1;
        if(in[i] == 0)
            qq.push(i);
    }
    while(!qq.empty())
    {
        cur = qq.front();
        qq.pop();
        for(auto it : rev2[cur])
        {
            all[it] |= all[cur];
            in[it] --;
            if(!in[it])
                qq.push(it);
        }
    }
    while(q--)
    {
        cin >> a >> b; a--; b--;
        if(scc[a] == scc[b] || all[scc[a]][scc[b]]) cout << "YES\n";
        else cout << "NO\n";
    }
}
