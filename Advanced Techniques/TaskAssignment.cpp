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
 
struct pq
{
    int len, par, cur;
    const bool operator>(const pq& other) const
    {
        return len > other.len;
    }
};

vector<int> adj[410];
queue<pii> q2;
int bfs[10010];
priority_queue<pq, vector<pq>, greater<pq>> nextInLine;
bitset<10010> visited;
int lim[410][410], cur[410][410], cost[410][410], par[410], dist[410], upDist[410], len[410];
queue<int> q;
vector<pii> ans;
int main()
{
    int n, a, d, st, en, curN, curD, curP, curF, flow = 0;
    cin >> n;
    for(int i = 0; i < n; i ++)
        for(int j = 0; j < n; j ++)
        {
            cin >> a;
            adj[i+1].push_back(j+n+1); adj[j+n+1].push_back(i+1); lim[i+1][j+n+1] ++; cost[i+1][j+n+1] += a; cost[j+n+1][i+1] -= a;
        }
    for(int i = 0; i < n; i ++)
        adj[0].push_back(i+1), adj[i+1].push_back(0), lim[0][i+1] ++;
    for(int i = 0; i < n; i ++)
        adj[i+n+1].push_back(2*n+1), adj[2*n+1].push_back(i+n+1), lim[i+n+1][2*n+1] ++;
    st = 0, en = 2*n+1;
    for(int i = 0; i < 410; i ++)
        dist[i] = 2000000000;
    dist[st] = 0; nextInLine.push({0, -1, st});
    while(!nextInLine.empty())
    {
        curN = nextInLine.top().cur; curD = nextInLine.top().len;
        nextInLine.pop();
        if(dist[curN] < curD) continue;
        for(auto it : adj[curN])
            if(lim[curN][it])
                if(dist[curN] + cost[curN][it] < dist[it])
                    dist[it] = dist[curN] + cost[curN][it], nextInLine.push({dist[it], -1, it});
    }
    while(true)
    {
        nextInLine.push({0, -1, st});
        visited.reset();
        fill(upDist, upDist+410, 2000000000); fill(len, len+410, 2000000000);
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
            for(int it : adj[curN])
                if(cur[curN][it] != lim[curN][it] && len[curN] + cost[curN][it] + dist[curN] - dist[it] < len[it])
                {
                    nextInLine.push({len[curN] + cost[curN][it] + dist[curN] - dist[it], curN, it});
                    len[it] = len[curN] + cost[curN][it] + dist[curN] - dist[it];
                }
        }
        if(len[en] == 2000000000)
        {
            for(int i = 1; i <= n; i ++)
                for(auto it : adj[i])
                    if(cur[i][it])
                    {
                        ans.push_back({i, it-n});
                        break;
                    }
            break;
        }
        curF = 2000000000; curN = en;
        while(curN != st)
        {
            curF = min(curF, lim[par[curN]][curN] - cur[par[curN]][curN]);
            curN = par[curN];
        }
        curN = en;
        while(curN != st)
        {
            cur[par[curN]][curN] += curF;
            cur[curN][par[curN]] -= curF;
            curN = par[curN];
        }
        flow += curF * (d + dist[en]);
        for(int i = 0; i < 410; i ++)
            dist[i] += upDist[i];
    }
    cout << flow << "\n";
    for(int i = 0; i < n; i ++)
        cout << ans[i].f << " " << ans[i].s << "\n";
}
