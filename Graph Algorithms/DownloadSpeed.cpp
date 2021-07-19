#include <iostream>
#include <string.h>
#include <random>
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
#include <complex>
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
using namespace std;
typedef pair<int, int> pii;
typedef pair<int, string> pis;
typedef pair<string, string> pss;
typedef pair<int, char> pic;
typedef pair<pii, int> piii;
typedef pair<double, double> pdd;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<ll, ll> pll;
typedef pair<int, ll> pil;
typedef pair<ull, ull> pull;
typedef complex<double> cd;
//#define max(n, m) ((n>m)?n:m)
//#define min(n, m) ((n<m)?n:m)
#define f first
#define s second
#define input() ios_base::sync_with_stdio(0);cin.tie(0);

vector<int> adj[510];
queue<int> nextInLine;
bitset<510> visited;
ll cur[510][510], lim[510][510], par[510];
int main()
{
    input();
    ll n, m, a, b, c, curN, curF, ans = 0;
    cin >> n >> m;
    for(int i = 0; i < m; i ++)
    {
        cin >> a >> b >> c; a--; b--;
        adj[a].push_back(b); adj[b].push_back(a);
        lim[a][b] += c;
    }
    par[0] = -1;
    while(true)
    {
        nextInLine.push(0);
        visited.reset(); visited[0] = true;
        while(!nextInLine.empty())
        {
            curN = nextInLine.front();
            nextInLine.pop();
            if(curN == n-1) continue;
            for(auto it : adj[curN])
                if(cur[curN][it] != lim[curN][it] && !visited[it])
                {
                    nextInLine.push(it);
                    visited[it] = true;
                    par[it] = curN;
                }
        }
        if(!visited[n-1]) break;
        for(auto it : adj[n-1])
        {
            if(!visited[it] || cur[it][n-1] == lim[it][n-1]) continue;
            curF = 2000000000; par[n-1] = it; curN = n-1;
            while(curN != 0)
            {
                curF = min(curF, lim[par[curN]][curN] - cur[par[curN]][curN]); curN = par[curN];
            }
            curN = n-1;
            while(curN != 0)
            {
                cur[par[curN]][curN] += curF; cur[curN][par[curN]] -= curF; curN = par[curN];
            }
            ans += curF;
        }
    }
    cout << ans << "\n";
}
