#include <iostream>
#include <string.h>
#include <fstream>
#include <stdio.h>
#include <iomanip>
#include <algorithm>
#include <math.h>
#include <vector>
#include <stack>
#include <queue>
#include <bitset>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef pair<int, int> pii;
typedef pair<int, string> pis;
typedef pair<int, char> pic;
typedef pair<pii, int> piii;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<ll, ll> pll;
//#define max(n, m) ((n>m)?n:m)
//#define min(n, m) ((n<m)?n:m)
#define f first
#define s second

struct chash { /// use most bits rather than just the lowest ones
    const uint64_t C = ll(2e18*(3.14))+71; // large odd number
    const int RANDOM = rand(); // random 32-bit number
    ll operator()(ll x) const {
        // https://gcc.gnu.org/onlinedocs/gcc/Other-Builtins.html
        return __builtin_bswap64((x^RANDOM)*C);
    }
};

vector<int> adj[100010];
vector<int> rev[100010];
ll coins[100010], total[100010];
gp_hash_table<int, null_type, chash> rev2[100010];
int in[100010];
bool visited[100010];
int scc[100010];
stack<int> ord;
queue<int> q;
int curCC = 1;
ll len[100010];
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
    int n, m, a, b, cur;
    ll ans = 0;
    cin >> n >> m;
    for(int i = 0; i < n; i ++)
        cin >> coins[i];
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
    for(int i = 0; i < n; i ++) total[scc[i]] += coins[i];
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
        if(in[i] == 0)
            q.push(i);
    while(!q.empty())
    {
        cur = q.front();
        q.pop();
        len[cur] += total[cur];
        for(auto it : rev2[cur])
        {
            len[it] = max(len[it], len[cur]);
            in[it] --;
            if(!in[it]) q.push(it);
        }
        ans = max(ans, len[cur]);
    }
    cout << ans << "\n";
}
