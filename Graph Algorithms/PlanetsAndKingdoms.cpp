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

vector<int> adj[100010];
vector<int> rev[100010];
bool visited[100010];
int scc[100010];
stack<int> ord;
int curCC = 1;
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
    int n, m, a, b;
    cin >> n >> m;
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
    cout << curCC-1 << "\n";
    for(int i = 0; i < n; i ++)
        cout << scc[i] << " ";
    cout << "\n";
}
