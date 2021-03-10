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
//#define max(n, m) ((n>m)?n:m)
//#define min(n, m) ((n<m)?n:m)
#define f first
#define s second

ll sz[100010];
vector<ll> ans;
priority_queue<pll, vector<pll>, greater<pll>> nextInLine;
vector<pll> adj[100010];
int main()
{
    ll n, m, k, curN, curD, one, two, three;
    cin >> n >> m >> k;
    for(int i = 0; i < m; i ++)
    {
        cin >> one >> two >> three;
        adj[one - 1].push_back(pii(two - 1, three));
    }
    nextInLine.push({0, 0});
    while(!nextInLine.empty() && sz[n - 1] < k)
    {
        curD = nextInLine.top().f;
        curN = nextInLine.top().s;
        nextInLine.pop();
        sz[curN] ++;
        if(curN == n - 1) ans.push_back(curD);
        if(sz[curN] <= k)
            for(int i = 0; i < adj[curN].size(); i ++)
                nextInLine.push({curD + adj[curN][i].s, adj[curN][i].f});
    }
    for(int i = 0; i < ans.size(); i ++)
        cout << ans[i] << " ";
    cout << "\n";
}
