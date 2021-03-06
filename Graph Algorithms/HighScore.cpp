#include <iostream>
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
typedef pair<pii, int> piii;
typedef long long ll;
typedef pair<ll, ll> pll;
//#define max(n, m) ((n>m)?n:m)
//#define min(n, m) ((n<m)?n:m)
#define f first
#define s second

struct edge
{
    ll s, e, c;
};

edge edges[5010];
ll dist[2510];
vector<int> adj[2510];
queue<int> nextInLine;
bool visited[2510];
int main()
{
    ll n, m, one, two, three, cur;
    cin >> n >> m;
    for(int i = 0; i <= n; i ++) dist[i] = 2000000000000000000;
    dist[1] = 0;
    for(int i = 0; i < m; i ++)
    {
        cin >> one >> two >> three;
        edges[i].s = one; edges[i].e = two; edges[i].c = -(three);
        adj[two].push_back(one);
    }
    nextInLine.push(n);
    while(!nextInLine.empty())
    {
        cur = nextInLine.front();
        nextInLine.pop();
        if(visited[cur]) continue;
        visited[cur] = true;
        for(auto it : adj[cur])
            nextInLine.push(it);
    }
    for(int i = 0; i < n; i ++)
        for(int j = 0; j < m; j ++)
        {
            if(dist[edges[j].s] + edges[j].c < dist[edges[j].e])
            {
                if(i >= n - 1 && visited[edges[j].e] && dist[edges[j].s] < 1000000000000000000) { dist[n] = -2000000000000000000; break; }
                dist[edges[j].e] = dist[edges[j].s] + edges[j].c;
            }
        }
    if(dist[n] == -2000000000000000000) { cout << -1 << "\n"; return 0; }
    dist[n] *= -1;
    cout << dist[n] << "\n";
}
