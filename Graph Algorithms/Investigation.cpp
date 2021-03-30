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

struct st
{
    ll idx, len;
    const bool operator>(const st& other) const
    {
        return len > other.len;
    }
};
priority_queue<st, vector<st>, greater<st>> nextInLine;
queue<int> q;
vector<pll> adj[200010];
set<int> adj2[200010];
ll len[200010];
ll mn[200010];
ll mx[200010];
ll cnt[200010];
int in[200010];
bool visited[200010];
int main()
{
    ll n, m, a, b, c, curN, curD;
    cin >> n >> m;
    for(int i = 0; i < m; i ++)
    {
        cin >> a >> b >> c; a--; b--;
        adj[a].push_back({b, c});
    }
    for(int i = 0; i < n; i ++)
        len[i] = 2000000000000000000;
    nextInLine.push({0, 0});
    len[0] = 0; cnt[0] = 1;
    while(!nextInLine.empty())
    {
        curD = nextInLine.top().len; curN = nextInLine.top().idx;
        nextInLine.pop();
        if(visited[curN]) continue;
        visited[curN] = true;
        for(int i = 0; i < adj[curN].size(); i ++)
        {
            if(len[curN] + adj[curN][i].s < len[adj[curN][i].f])
            {
                len[adj[curN][i].f] = len[curN] + adj[curN][i].s;
                nextInLine.push({adj[curN][i].f, len[adj[curN][i].f]});
                mn[adj[curN][i].f] = mn[curN] + 1;
                mx[adj[curN][i].f] = mx[curN] + 1;
                cnt[adj[curN][i].f] = cnt[curN];
            }
            else if(len[curN] + adj[curN][i].s == len[adj[curN][i].f])
            {
                nextInLine.push({adj[curN][i].f, len[adj[curN][i].f]});
                mn[adj[curN][i].f] = min(mn[adj[curN][i].f], mn[curN] + 1);
                mx[adj[curN][i].f] = max(mx[adj[curN][i].f], mx[curN] + 1);
                cnt[adj[curN][i].f] = (cnt[curN] + cnt[adj[curN][i].f]) % 1000000007;
            }
        }
    }
    cout << len[n-1] << " " << cnt[n-1] % 1000000007 << " " << mn[n-1] << " " << mx[n-1] << "\n";
}
