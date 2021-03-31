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

vector<int> adj[100010][2]; // regular and reversed
bool visited[100010];
void dfs(int cur, int par, int type)
{
    visited[cur] = true;
    for(auto it : adj[cur][type])
    {
        if(it == par || visited[it]) continue;
        dfs(it, cur, type);
    }
}
int main()
{
    int n, m, a, b;
    cin >> n >> m;
    for(int i = 0; i < m; i ++)
    {
        cin >> a >> b; a--; b--;
        adj[a][0].push_back(b);
        adj[b][1].push_back(a);
    }
    memset(visited, false, sizeof(visited));
    dfs(0, -1, 0);
    for(int i = 0; i < n; i ++)
        if(!visited[i])
        {
            cout << "NO\n1 " << i+1 << "\n";
            return 0;
        }
    memset(visited, false, sizeof(visited));
    dfs(0, -1, 1);
    for(int i = 0; i < n; i ++)
        if(!visited[i])
        {
            cout << "NO\n" << i+1 << " " << "1\n";
            return 0;
        }
    cout << "YES\n";
}
