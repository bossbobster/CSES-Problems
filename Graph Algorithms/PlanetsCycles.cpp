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
int cycle[200010];
bool visited[200010];
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
    if(good) sz[cycle[adj[cur]]] ++;
    else distTo[cur] = distTo[adj[cur]] + 1;
    if(!cycle[cur])
        cycle[cur] = cycle[adj[cur]];
    else good = false;
}
int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i ++)
    {
        cin >> adj[i]; adj[i] --;
    }
    for(int i = 0; i < n; i ++)
    {
        if(visited[i]) continue;
        dfs(i);
    }
    for(int i = 0; i < n; i ++)
        cout << distTo[i] + sz[cycle[i]] << " ";
    cout << "\n";
}
