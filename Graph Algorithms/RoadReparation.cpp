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

ll len[100010];
priority_queue<pii, vector<pii>, greater<pii>> nextInLine;
vector<pii> adj[100010];
bool finalized[100010];
int main()
{
    ll n, m, curN, curD, one, two, three, ans = 0;
    cin >> n >> m;
    for(int i = 0; i < m; i ++)
    {
        cin >> one >> two >> three;
        adj[one - 1].push_back({two - 1, three});
        adj[two - 1].push_back({one - 1, three});
    }
    for(int i = 0; i < n; i ++)
        len[i] = 2000000000;
    nextInLine.push({0, 0});
    len[0] = 0;
    while(!nextInLine.empty())
    {
        curD = nextInLine.top().f; curN = nextInLine.top().s;
        nextInLine.pop();
        if(finalized[curN] || curD > len[curN]) continue;
        for(int i = 0; i < adj[curN].size(); i ++)
            if(adj[curN][i].s < len[adj[curN][i].f] && !finalized[adj[curN][i].f])
            {
                len[adj[curN][i].f] = adj[curN][i].s;
                nextInLine.push({len[adj[curN][i].f], adj[curN][i].f});
            }
        finalized[curN] = true;
    }
    for(int i = 0; i < n; i ++)
    {
        if(len[i] == 2000000000) { cout << "IMPOSSIBLE\n"; return 0; }
        ans += len[i];
    }
    cout << ans << "\n";
}
