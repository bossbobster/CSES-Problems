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

vector<int> adj[100010];
queue<pii> nextInLine;
bool visited[100010];
int par[100010];
vector<int> ans;
int main()
{
    int n, m, one, two, cur, pre, idx;
    cin >> n >> m;
    for(int i = 0; i < m; i ++)
    {
        cin >> one >> two; one --; two --;
        adj[one].push_back(two); adj[two].push_back(one);
    }
    for(int i = 0; i <= n; i ++) par[i] = -1;
    nextInLine.push({0, -1});
    while(!nextInLine.empty())
    {
        cur = nextInLine.front().f; pre = nextInLine.front().s;
        nextInLine.pop();
        if(visited[cur]) continue;
        visited[cur] = true;
        par[cur] = pre;
        for(auto i : adj[cur])
            nextInLine.push({i, cur});
    }
    idx = n - 1;
    while(idx != -1)
    {
        ans.push_back(idx + 1);
        idx = par[idx];
    }
    for(int i = 0; i < ans.size() / 2; i ++) swap(ans[i], ans[ans.size() - i - 1]);
    if(ans[0] != 1) { cout << "IMPOSSIBLE\n"; return 0; }
    cout << ans.size() << "\n";
    for(int i = 0; i < ans.size(); i ++)
        cout << ans[i] << " ";
    cout << "\n";
}
