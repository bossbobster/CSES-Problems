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

int n, m, one, two;
vector<int> adj[100010];
vector<int> ans; vector<int> emp;
int parArr[100010];
vector<int> dfs(int cur, bool *visited, bool *stac)
{
    if(!ans.empty()) return ans;
    if(!visited[cur])
    {
        visited[cur] = stac[cur] = true;
        for(auto it : adj[cur])
        {
            parArr[it] = cur;
            if(!visited[it] && !dfs(it, visited, stac).empty())
                return ans;
            if(stac[it])
            {
                int tmp = it;
                do
                {
                    ans.push_back(tmp + 1);
                    tmp = parArr[tmp];
                } while(tmp != it && tmp != -1);
                ans.push_back(it + 1);
                for(int i = 0; i < ans.size() / 2; i ++) swap(ans[i], ans[ans.size() - i - 1]);
                return ans;
            }
        }
    }
    stac[cur] = false;
    return emp;
}
int main()
{
    cin >> n >> m;
    for(int i = 0; i < m; i ++)
    {
        cin >> one >> two; one --; two --;
        adj[one].push_back(two);
    }
    for(int i = 0; i < n; i ++) parArr[i] = -1;
    bool *vis = new bool[100010]; bool *st = new bool[100010];
    for(int i = 0; i < n; i ++) vis[i] = st[i] = false;
    for(int i = 0; i < n; i ++)
        if(!dfs(i, vis, st).empty())
            break;
    if(ans.size() == 0) { cout << "IMPOSSIBLE\n"; return 0; }
    cout << ans.size() << "\n";
    for(int i = 0; i < ans.size(); i ++)
        cout << ans[i] << " ";
    cout << "\n";
}
