#include <iostream>
#include <string.h>
#include <fstream>
#include <stdio.h>
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
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
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

unordered_set<int> adj[200010], rev[200010], adj2[200010];
bool visited[200010];
int scc[200010];
vector<int> sc[200010];
queue<int> q;
int in[200010];
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
    sc[curCC].push_back(cur);
    for(auto it : rev[cur])
    {
        if(scc[it]) continue;
        dfs2(it);
    }
}
int other[200010];
char ans[100010];
int main()
{
    char ch1, ch2;
    int n, m, a, b, c1, c2, cur;
    cin >> n >> m;
    for(int i = 0; i < m*2; i ++)
        other[i] = ((i%2==0)?i+1:i-1);
    for(int i = 0; i < n; i ++)
    {
        cin >> ch1 >> a >> ch2 >> b; a--; b--;
        if(ch1 == '+') c1 = 0; else c1 = 1;
        if(ch2 == '+') c2 = 0; else c2 = 1;
        adj[other[a*2+c1]].insert(b*2+c2); adj[other[b*2+c2]].insert(a*2+c1);
        rev[b*2+c2].insert(other[a*2+c1]); rev[a*2+c1].insert(other[b*2+c2]);
    }
    memset(visited, false, sizeof(visited));
    for(int i = 0; i < 2*m; i ++)
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
    for(int i = 0; i < m*2; i += 2)
        if(scc[i] == scc[i+1] && scc[i] != 0)
        {
            cout << "IMPOSSIBLE\n"; return 0;
        }
    for(int i = 0; i < m*2; i ++)
        for(auto it : rev[i])
        {
            if(scc[it] != scc[i])
            {
                if(adj2[scc[i]].find(scc[it]) == adj2[scc[i]].end()) in[scc[it]] ++;
                adj2[scc[i]].insert(scc[it]);
            }
        }
    for(int i = 1; i < curCC; i ++)
        if(in[i] == 0)
            q.push(i);
    memset(ans, 'a', sizeof(ans));
    while(!q.empty())
    {
        cur = q.front(); q.pop();
        for(auto it : sc[cur])
            if(ans[it/2] == 'a')
            {
                if(it % 2 == 0) ans[it/2] = '+';
                else ans[it/2] = '-';
            }
        for(auto it : adj2[cur])
        {
            in[it] --;
            if(!in[it]) q.push(it);
        }
    }
    for(int i = 0; i < m; i ++)
        cout << ((ans[i]=='a')?'+':ans[i]) << " ";
    cout << "\n";
}
