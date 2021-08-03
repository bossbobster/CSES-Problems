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

struct edge
{
    int n, l, c, cur, idx, id;
};
struct pq
{
    int len; edge par; int cur;
    const bool operator>(const pq& other) const
    {
        return len > other.len;
    }
};
int n, m, k, st, en, a, b, d, curN, curD, curF, flow = 0, ans = 0;
vector<edge> adj[510];
priority_queue<pq, vector<pq>, greater<pq>> nextInLine;
bitset<510> visited;
bitset<510> edgeVis[510];
int dist[510], upDist[510], len[510];
queue<int> q;
vector<int> v;
vector<vector<int>> ansV;
edge par[510];
void dfs(int node)
{
    v.push_back(node+1);
    if(node == n-1) return;
    for(auto it : adj[node])
        if(it.cur == 1 && !edgeVis[node][it.n])
        {
            edgeVis[node][it.n] = 1;
            dfs(it.n);
            break;
        }
}
int main()
{
    input();
    edge curP, it;
    pq tmp;
    bool good = false;
    cin >> n >> m >> k;
    st = 0; en = n-1;
    for(int i = 0; i < m; i ++)
    {
        cin >> a >> b; a--; b--;
        adj[a].push_back({b, 1, 1, 0, 0, i}); adj[b].push_back({a, 0, -1, 0, 0, i});
    }
    for(int i = 0; i < n; i ++)
        dist[i] = 2000000000;
    dist[st] = 0; q.push(st);
    while(!q.empty())
    {
        curN = q.front(); q.pop();
        for(auto it : adj[curN])
            if(it.l != 0)
                if(dist[curN] + it.c < dist[it.n])
                    dist[it.n] = dist[curN] + it.c, q.push(it.n);
    }
    while(true)
    {
        nextInLine.push({0, {-1, -1, -1, -1, -1, -1}, st});
        visited.reset();
        fill(upDist, upDist+n, 2000000000); fill(len, len+n, 2000000000);
        len[st] = 0;
        while(!nextInLine.empty())
        {
            curD = nextInLine.top().len; curP = nextInLine.top().par; curN = nextInLine.top().cur;
            nextInLine.pop();
            if(len[curN] < curD) continue;
            upDist[curN] = curD;
            par[curN] = curP;
            if(curN == en)
            {
                d = curD;
                continue;
            }
            for(int i = 0; i < adj[curN].size(); i ++)
            {
                it = adj[curN][i];
                if(it.cur != it.l && len[curN] + it.c + dist[curN] - dist[it.n] < len[it.n])
                {
                    tmp.cur = it.n; tmp.par = {curN, it.l, it.c, it.cur, i, it.id}; tmp.len = len[curN] + it.c + dist[curN] - dist[it.n];
                    nextInLine.push(tmp);
                    len[it.n] = len[curN] + it.c + dist[curN] - dist[it.n];
                }
            }
        }
        if(len[en] == 2000000000) break;
        curF = 2000000000; curN = en;
        while(curN != st)
        {
            curF = min(curF, par[curN].l - par[curN].cur);
            curN = par[curN].n;
        }
        curN = en;
        while(curN != st)
        {
            adj[par[curN].n][par[curN].idx].cur += curF;
            for(int i = 0; i < adj[curN].size(); i ++)
                if(par[curN].id == adj[curN][i].id)
                {
                    adj[curN][i].cur -= curF;
                    break;
                }
            curN = par[curN].n;
        }
        flow += curF;
        if(flow >= k)
        {
            flow -= curF;
            ans += (k - flow) * (d + dist[en]); flow = k;
            cout << ans << "\n";
            while(flow--)
            {
                v.clear();
                dfs(0);
                ansV.push_back(v);
            }
            for(auto vec : ansV)
            {
                cout << vec.size() << "\n";
                for(auto it : vec)
                    cout << it << ((it==vec.back())?"\n":" ");
            }
            good = true; break;
        }
        ans += curF * (d + dist[en]);
        for(int i = 0; i < n; i ++)
            dist[i] += upDist[i];
    }
    if(!good) cout << "-1\n";
}
