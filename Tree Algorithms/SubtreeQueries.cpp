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
#pragma GCC optimize ("O2")
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
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
#define input(x) ios_base::sync_with_stdio(x); cin.tie(x);

int n, q;
ll nums[200010];
vector<int> adj[200010];
pii endpts[200010];
ll bit[200010];
ll sum(int idx)
{
    ll ans = 0;
    idx ++;
    while(idx > 0)
    {
        ans += bit[idx];
        idx -= idx & (-idx);
    }
    return ans;
}
void update(int idx, ll val)
{
    idx ++;
    while(idx <= n)
    {
        bit[idx] += val;
        idx += idx & (-idx);
    }
}
int cnt = 0;
void euler(int cur, int par)
{
    endpts[cur].f = cnt ++;
    for(auto it : adj[cur])
        if(it != par)
            euler(it, cur);
    endpts[cur].s = cnt - 1;
}
int main()
{
    input(0);
    int a, b, c;
    cin >> n >> q;
    for(int i = 0; i < n; i ++)
        cin >> nums[i];
    for(int i = 0; i < n-1; i ++)
    {
        cin >> a >> b; a--; b--;
        adj[a].push_back(b); adj[b].push_back(a);
    }
    euler(0, -1);
    for(int i = 0; i < n; i ++)
        update(endpts[i].f, nums[i]);
    while(q--)
    {
        cin >> a;
        if(a == 1)
        {
            cin >> b >> c; b--;
            update(endpts[b].f, c - nums[b]); nums[b] = c;
        }
        else
        {
            cin >> b; b--;
            cout << sum(endpts[b].s) - sum(endpts[b].f-1) << "\n";
        }
    }
}
