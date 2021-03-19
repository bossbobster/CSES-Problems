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
typedef pair<pii, int> piii;
typedef long long ll;
typedef pair<ll, ll> pll;
#define max(n, m) ((n>m)?n:m)
//#define min(n, m) ((n<m)?n:m)
#define f first
#define s second

int ans = 0;
vector<int> adj[200010];
bool used[200010];
void dfs(int cur, int par)
{
    if(adj[cur].size() == 1)
        if(!used[cur] && !used[adj[cur][0]])
        {
            ans ++;
            used[cur] = used[adj[cur][0]] = true;
        }
    for(auto it : adj[cur])
    {
        if(it == par) continue;
        dfs(it, cur);
        if(!used[cur] && !used[it])
        {
            ans ++;
            used[cur] = used[it] = true;
        }
    }
}
int main()
{
    int n, a, b;
    cin >> n;
    for(int i = 0; i < n - 1; i ++)
    {
        cin >> a >> b; a--; b--;
        adj[a].push_back(b); adj[b].push_back(a);
    }
    dfs(0, -1);
    cout << ans << "\n";
}
