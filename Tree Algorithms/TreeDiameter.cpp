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

vector<int> adj[200010];
int ans[200010];
int mx1, mx2, ansans = 0;
void dfs(int cur, int par)
{
    for(auto it : adj[cur])
    {
        if(it == par) continue;
        dfs(it, cur);
        ans[cur] = max(ans[it], ans[cur]);
    }
    mx1 = mx2 = 0;
    for(auto it : adj[cur])
    {
        if(ans[it] > mx1) { mx2 = mx1; mx1 = ans[it]; }
        else if(ans[it] > mx2) { mx2 = ans[it]; }
    }
    ansans = max(ansans, mx1 + mx2);
    ans[cur] ++;
}
int main()
{
    int n, a, b;
    cin >> n;
    if(n <= 3) { cout << n - 1 << "\n"; return 0; }
    for(int i = 0; i < n - 1; i ++)
    {
        cin >> a >> b; a--; b--;
        adj[a].push_back(b); adj[b].push_back(a);
    }
    dfs(0, -1);
    cout << ansans << "\n";
}
