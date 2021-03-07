#include <iostream>
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
#define min(n, m) ((n<m)?n:m)
#define f first
#define s second

struct st
{
    ll d, n;
    bool used;
    const bool operator>(const st& other) const
    {
        return d > other.d;
    }
};

ll len[100010][2];
priority_queue<st, vector<st>, greater<st>> nextInLine;
vector<pll> adj[100010];
vector<pll> adj2[100010];
int main()
{
    ll v, e, curN, curD, one, two, three;
    bool usd = false;
    cin >> v >> e;
    for(int i = 0; i < e; i ++)
    {
        cin >> one >> two >> three;
        adj[one - 1].push_back({two - 1, three});
        adj2[one - 1].push_back({two - 1, three / 2});
    }
    for(int i = 0; i < v; i ++)
        len[i][0] = len[i][1] = 2000000000000000000;
    nextInLine.push({0, 0, usd});
    len[0][usd] = 0;
    while(!nextInLine.empty())
    {
        curD = nextInLine.top().d; curN = nextInLine.top().n; usd = nextInLine.top().used;
        nextInLine.pop();
        if(len[curN][usd] < curD) continue;
        for(int i = 0; i < adj[curN].size(); i ++)
            if(len[curN][usd] + adj[curN][i].s < len[adj[curN][i].f][usd])
            {
                len[adj[curN][i].f][usd] = len[curN][usd] + adj[curN][i].s;
                nextInLine.push({len[curN][usd] + adj[curN][i].s, adj[curN][i].f, usd});
            }
        if(!usd)
            for(int i = 0; i < adj2[curN].size(); i ++)
                if(len[curN][usd] + adj2[curN][i].s < len[adj2[curN][i].f][1])
                {
                    len[adj2[curN][i].f][1] = len[curN][usd] + adj2[curN][i].s;
                    nextInLine.push({len[adj2[curN][i].f][1], adj2[curN][i].f, 1});
                }
    }
    cout << len[v - 1][1] << "\n";
}
