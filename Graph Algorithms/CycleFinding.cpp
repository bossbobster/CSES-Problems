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
#define max(n, m) ((n>m)?n:m)
#define min(n, m) ((n<m)?n:m)
#define f first
#define s second

struct edge
{
    ll s, e, c;
};
 
edge edges[5010];
ll dist[2510];
vector<ll> adj[2510];
ll par[2510];
vector<ll> ans;
set<ll> in;
unordered_map<ll, int> pos;
int main()
{
    ll n, m, one, two, three, nd = 0, cur;
    cin >> n >> m;
    for(int i = 0; i <= n; i ++) dist[i] = 0;
    for(int i = 0; i < m; i ++)
    {
        cin >> one >> two >> three;
        edges[i].s = one; edges[i].e = two; edges[i].c = three;
        adj[one].push_back(two);
    }
    for(int i = 0; i < n; i ++)
        for(int j = 0; j < m; j ++)
        {
            if(dist[edges[j].s] + edges[j].c < dist[edges[j].e])
            {
                if(i >= n - 1) { dist[n] = -2000000000000000000; nd = edges[j].s; break; }
                dist[edges[j].e] = dist[edges[j].s] + edges[j].c;
                par[edges[j].e] = edges[j].s;
            }
        }
    if(dist[n] == -2000000000000000000)
    {
        cout << "YES\n";
        cur = nd;
        int idx = 0;
        while(in.find(cur) == in.end())
        {
            ans.push_back(cur);
            in.insert(cur);
            pos[cur] = idx; idx ++;
            cur = par[cur];
        }
        ans.push_back(cur);
        for(int i = pos[cur]; i < (ans.size() + pos[cur]) / 2; i ++)
            swap(ans[i], ans[ans.size() - i + pos[cur] - 1]);
        for(int i = pos[cur]; i < ans.size(); i ++)
            cout << ans[i] << " ";
        cout << "\n";
        return 0;
    }
    cout << "NO\n";
}
