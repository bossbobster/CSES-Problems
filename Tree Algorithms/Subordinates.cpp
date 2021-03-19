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
void dfs(int cur, int par)
{
    for(auto nx : adj[cur])
    {
        if(nx == par) continue;
        dfs(nx, cur);
        ans[cur] += ans[nx];
    }
    ans[cur] ++;
}
int main()
{
    int n, num;
    cin >> n;
    for(int i = 1; i < n; i ++)
    {
        cin >> num;
        adj[num - 1].push_back(i);
    }
    dfs(0, -1);
    for(int i = 0; i < n; i ++)
        cout << ans[i] - 1 << " ";
    cout << "\n";
}
