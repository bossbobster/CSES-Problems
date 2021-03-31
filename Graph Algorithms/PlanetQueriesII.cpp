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
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
using namespace std;
typedef pair<int, int> pii;
typedef pair<int, string> pis;
typedef pair<int, char> pic;
typedef pair<pii, int> piii;
typedef long long ll;
typedef pair<ll, ll> pll;
//#define max(n, m) ((n>m)?n:m)
//#define min(n, m) ((n<m)?n:m)
#define f first
#define s second

int adj[200010];
int dist[200010];
int cycle[200010];
bool visited[200010];
int to[200010][40];
bool in[200010];
int sz[200010];
int distTo[200010];
int curC = 1;
bool good;
void dfs(int cur)
{
    visited[cur] = true;
    if(!visited[adj[cur]]) dfs(adj[cur]);
    else
        if(cycle[adj[cur]] == 0) { cycle[adj[cur]] = curC; curC ++; good = true; }
    if(good) { sz[cycle[adj[cur]]] ++; in[cur] = true; }
    else distTo[cur] = distTo[adj[cur]] + 1;
    if(!cycle[cur])
    {
        cycle[cur] = cycle[adj[cur]];
        dist[cur] = dist[adj[cur]] + 1;
    }
    else good = false;
}
int query(int a, int b)
{
    if(b == 0) return a;
    int pw = 0;
    while(b != 0)
    {
        if(b % 2 == 1) a = to[a][pw];
        pw ++;
        b /= 2;
    }
    return a;
}
int main()
{
    int n, q, a, b, num = 2, nx;
    cin >> n >> q;
    for(int i = 0; i < n; i ++)
    {
        cin >> adj[i]; adj[i] --; to[i][0] = adj[i];
    }
    for(int j = 1; j <= log2(400000); j ++)
    {
        for(int i = 0; i < n; i ++)
            to[i][j] = to[to[i][j-1]][j-1];
        num *= 2;
    }
    for(int i = 0; i < n; i ++)
    {
        if(visited[i]) continue;
        dfs(i);
    }
    for(int i = 0; i < q; i ++)
    {
        cin >> a >> b; a--; b--;
        if((in[a] && !in[b]) || cycle[a] != cycle[b] || (!in[a] && !in[b] && dist[a] < dist[b])) { cout << "-1\n"; continue; }
        if(!in[a] && !in[b])
        {
            nx = query(a, dist[a] - dist[b]);
            if(nx != b) { cout << "-1\n"; continue; }
            cout << dist[a] - dist[b] << "\n";
        }
        else if(in[a] && in[b])
        {
            if(dist[a] >= dist[b]) { cout << dist[a] - dist[b] << "\n"; continue; }
            cout << sz[cycle[a]] - (dist[b] - dist[a]) << "\n";
        }
        else
        {
            nx = query(a, distTo[a]);
            if(dist[nx] >= dist[b]) { cout << dist[a] - dist[b] << "\n"; continue; }
            cout << distTo[a] + sz[cycle[a]] - (dist[b] - dist[nx]) << "\n";
        }
    }
}
