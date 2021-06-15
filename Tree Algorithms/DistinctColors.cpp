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
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
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

struct chash
{
    const uint64_t C = ll(2e18*(3.14))+71; // large odd number
    const int RANDOM = rand(); // random 32-bit number
    ll operator()(ll x) const
    {
        // https://gcc.gnu.org/onlinedocs/gcc/Other-Builtins.html
        return __builtin_bswap64((x^RANDOM)*C);
    }
};

int n, a, b, mx;
int nums[200010];
vector<int> adj[200010];
gp_hash_table<int, null_type, chash>* c[200010];
int ans[200010];
void dfs(int cur, int par)
{
    for(auto it : adj[cur])
    {
        if(it == par) continue;
        dfs(it, cur);
    }
    if(adj[cur].size() == 1 && cur != 0) c[cur] = new gp_hash_table<int, null_type, chash>;
    else
    {
        mx = -1;
        for(auto it : adj[cur])
        {
            if(it == par) continue;
            if(mx == -1) mx = it;
            if(c[it]->size() > c[mx]->size())
                mx = it;
        }
        c[cur] = c[mx];
        for(auto it : adj[cur])
            if(it != par && it != mx)
                for(auto a : *c[it])
                    c[cur]->insert(a);
    }
    c[cur]->insert(nums[cur]);
    ans[cur] = (int)c[cur]->size();
}
int main()
{
    input();
    cin >> n;
    for(int i = 0; i < n; i ++)
        cin >> nums[i];
    for(int i = 0; i < n-1; i ++)
    {
        cin >> a >> b; a--; b--;
        adj[a].push_back(b); adj[b].push_back(a);
    }
    dfs(0, -1);
    for(int i = 0; i < n; i ++)
        cout << ans[i] << ((i==n-1)?"\n":" ");
}
