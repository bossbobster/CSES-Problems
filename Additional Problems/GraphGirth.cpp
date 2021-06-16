#include <iostream>
#include <string.h>
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
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
using namespace std;
typedef pair<int, int> pii;
typedef pair<int, string> pis;
typedef pair<int, char> pic;
typedef pair<pii, int> piii;
typedef pair<double, double> pdd;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<ll, ll> pll;
typedef pair<int, ll> pil;
typedef pair<ull, ull> pull;
//#define max(n, m) ((n>m)?n:m)
//#define min(n, m) ((n<m)?n:m)
#define f first
#define s second
#define input() ios_base::sync_with_stdio(0);cin.tie(0);

int n, m, a, b, ans = 2000000000;
vector<int> adj[2510];
bitset<2510> visited;
bool done;
void dfs(int cur, int par, int d)
{
    if(d >= ans) return;
    if(visited[cur])
    {
        ans = min(ans, d);
        return;
    }
    visited[cur] = 1;
    for(auto it : adj[cur])
        if(it != par)
            dfs(it, cur, d+1);
    visited[cur] = 0;
}
int main()
{
    cin >> n >> m;
    for(int i = 0; i < m; i ++)
    {
        cin >> a >> b; a--; b--;
        adj[a].push_back(b); adj[b].push_back(a);
    }
    for(int i = 0; i < n; i ++)
    {
        visited.reset(); done = false;
        dfs(i, -1, 0);
    }
    cout << ((ans==2000000000)?-1:ans) << "\n";
}
