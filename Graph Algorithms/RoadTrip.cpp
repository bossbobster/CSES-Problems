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

int n, m, one, two;
vector<int> adj[100010];
vector<int> ans;
int parArr[100010];
bool visited[100010];
void dfs(int cur, int par)
{
    if(!ans.empty()) return;
    visited[cur] = true;
    for(auto it : adj[cur])
    {
        if(!ans.empty()) continue;
        if(it == par) continue;
        parArr[it] = cur;
        if(visited[it])
        {
            int tmp = it;
            do
            {
                ans.push_back(tmp + 1);
                tmp = parArr[tmp];
            } while(tmp != it);
            ans.push_back(it + 1);
            for(int i = 0; i < ans.size() / 2; i ++) swap(ans[i], ans[ans.size() - i - 1]);
            return;
        }
        dfs(it, cur);
    }
}
int main()
{
    cin >> n >> m;
    for(int i = 0; i < m; i ++)
    {
        cin >> one >> two; one --; two --;
        adj[one].push_back(two); adj[two].push_back(one);
    }
    for(int i = 0; i < n; i ++) parArr[i] = -1;
    for(int i = 0; i < n; i ++)
    {
        if(ans.size() || visited[i]) continue;
        dfs(i, -1);
    }
    if(ans.size() == 0) { cout << "IMPOSSIBLE\n"; return 0; }
    cout << ans.size() << "\n";
    for(int i = 0; i < ans.size(); i ++)
        cout << ans[i] << " ";
    cout << "\n";
}
