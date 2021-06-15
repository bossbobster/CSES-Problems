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

int n, a, b;
vector<int> adj[200010];
int sz[200010];
bool done = false;
void dfs(int cur, int par)
{
    if(done) return;
    bool good = true;
    for(auto it : adj[cur])
    {
        if(done) return;
        if(it == par) continue;
        dfs(it, cur);
        sz[cur] += sz[it];
        if(sz[it] > n/2) good = false;
    }
    sz[cur] ++;
    if(n - sz[cur] > n/2) good = false;
    if(good)
    {
        cout << cur+1 << "\n";
        done = true;
    }
}
int main()
{
    cin >> n;
    for(int i = 0; i < n-1; i ++)
    {
        cin >> a >> b; a--; b--;
        adj[a].push_back(b); adj[b].push_back(a);
    }
    dfs(0, -1);
}
