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
 
vector<int> adj[210];
queue<int> nextInLine;
bitset<210> visited;
int cur[210][210], lim[210][210], par[210];
vector<pii> v, coins;
string board[110];
int main()
{
    input();
    int n, curN, curF, ans = 0;
    cin >> n;
    for(int i = 0; i < n; i ++)
    {
        cin >> board[i];
        for(int j = 0; j < n; j ++)
            if(board[i][j] == 'o')
                coins.push_back({i, j});
    }
    for(int i = 1; i <= n; i ++)
        adj[0].push_back(i), adj[i].push_back(0), lim[0][i] ++;
    for(int i = 1; i <= n; i ++)
        adj[n+i].push_back(n*2+1), adj[n*2+1].push_back(n+i), lim[n+i][n*2+1] ++;
    for(auto it : coins)
        adj[it.f+1].push_back(it.s+n+1), adj[it.s+n+1].push_back(it.f+1), lim[it.f+1][it.s+n+1] += 2000000000;
    par[0] = -1;
    while(true)
    {
        nextInLine.push(0);
        visited.reset(); visited[0] = true;
        while(!nextInLine.empty())
        {
            curN = nextInLine.front();
            nextInLine.pop();
            if(curN == n*2+1) continue;
            for(auto it : adj[curN])
                if(cur[curN][it] != lim[curN][it] && !visited[it])
                {
                    nextInLine.push(it);
                    visited[it] = true;
                    par[it] = curN;
                }
        }
        if(!visited[n*2+1])
        {
            for(int i = 1; i <= n; i ++)
                if(!visited[i])
                    v.push_back({1, i});
            for(int i = n+1; i <= 2*n; i ++)
                if(visited[i])
                    v.push_back({2, i-n});
            break;
        }
        for(auto it : adj[n*2+1])
        {
            if(!visited[it] || cur[it][n*2+1] == lim[it][n*2+1]) continue;
            curF = 2000000000; par[n*2+1] = it; curN = n*2+1;
            while(curN != 0)
            {
                curF = min(curF, lim[par[curN]][curN] - cur[par[curN]][curN]); curN = par[curN];
            }
            curN = n*2+1;
            while(curN != 0)
            {
                cur[par[curN]][curN] += curF; cur[curN][par[curN]] -= curF; curN = par[curN];
            }
            ans += curF;
        }
    }
    cout << ans << "\n";
    for(int i = 0; i < v.size(); i ++)
        cout << v[i].f << " " << v[i].s << "\n";
}
