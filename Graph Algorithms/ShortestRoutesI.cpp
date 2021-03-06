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

ll len[100010];
priority_queue<pll, vector<pll>, greater<pll>> nextInLine;
vector<pll> adj[100010];
int main()
{
    ll v, e, curN, curD, one, two, three;
    cin >> v >> e;
    for(int i = 0; i < e; i ++)
    {
        cin >> one >> two >> three;
        adj[one - 1].push_back(pii(two - 1, three));
    }
    for(int i = 0; i < v; i ++)
        len[i] = 2000000000000000000;
    nextInLine.push({0, 0});
    len[0] = 0;
    while(!nextInLine.empty())
    {
        curD = nextInLine.top().f;
        curN = nextInLine.top().s;
        nextInLine.pop();
        if(len[curN] < curD) continue;
        for(int i = 0; i < adj[curN].size(); i ++)
            if(len[curN] + adj[curN][i].s < len[adj[curN][i].f])
            {
                len[adj[curN][i].f] = len[curN] + adj[curN][i].s;
                nextInLine.push({len[adj[curN][i].f], adj[curN][i].f});
            }
    }
    for(int i = 0; i < v; i ++)
    {
        if(len[i] != 2000000000000000000) cout << len[i] << " ";
        else cout << -1 << " ";
    }
    cout << "\n";
}
