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
#include <array>
#include <bitset>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <complex>
#include <valarray>
#include <memory>
#include <cassert>
#include <chrono>
#include <type_traits>
#include <stdexcept>
#include <string_view>
using namespace std;
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
typedef pair<int, int> pii;
typedef pair<int, string> pis;
typedef pair<pis, string> piss;
typedef pair<int, short> pish;
typedef pair<string, string> pss;
typedef pair<int, char> pic;
typedef pair<pii, int> piii;
typedef pair<double, double> pdd;
typedef pair<double, int> pdi;
typedef pair<float, float> pff;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef unsigned short ushort;
typedef pair<uint, uint> puint;
typedef pair<ll, ll> pll;
typedef pair<pll, ll> plll;
typedef pair<pll, ld> plld;
typedef pair<ld, int> pldi;
typedef pair<int, ll> pil;
typedef pair<ll, int> pli;
typedef pair<ull, ull> pull;
typedef pair<ld, ld> pld;
typedef complex<double> cd;
//#define max(n, m) ((n>m)?n:m)
//#define min(n, m) ((n<m)?n:m)
#define f first
#define s second
#define input() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
//#define eps 1e-8
//#define eps2 1e-15
#define leni(x) sizeof(x)/sizeof(int)
#define v(i,j,k) for(i=j;i<k;i++)
//#define cin fin
//#define cout fout
//#define fin cin
//#define fout cout
#pragma GCC optimize("O1,O2,O3,Ofast,unroll-loops")

struct edge
{
    ll s, e, c;
};
 
edge edges[5010];
ll dist[2510];
vector<ll> adj[2510];
ll par[2510];
vector<ll> ans;
set<ll> in;
unordered_map<ll, int> pos;
int main()
{
    input();
    ll n, m, one, two, three, nd = 0, cur;
    cin >> n >> m;
    for(int i = 0; i <= n; i ++) dist[i] = 0;
    for(int i = 0; i < m; i ++)
    {
        cin >> one >> two >> three;
        edges[i].s = one; edges[i].e = two; edges[i].c = three;
        adj[one].push_back(two);
    }
    for(int i = 0; i < n; i ++)
        for(int j = 0; j < m; j ++)
        {
            if(dist[edges[j].s] + edges[j].c < dist[edges[j].e])
            {
                if(i >= n - 1) { par[edges[j].e] = edges[j].s; dist[n] = -2000000000000000000; nd = edges[j].s; break; }
                dist[edges[j].e] = dist[edges[j].s] + edges[j].c;
                par[edges[j].e] = edges[j].s;
            }
        }
    if(dist[n] == -2000000000000000000)
    {
        cout << "YES\n";
        cur = nd;
        int idx = 0;
        while(in.find(cur) == in.end())
        {
            ans.push_back(cur);
            in.insert(cur);
            pos[cur] = idx; idx ++;
            cur = par[cur];
        }
        ans.push_back(cur);
        for(int i = pos[cur]; i < (ans.size() + pos[cur]) / 2; i ++)
            swap(ans[i], ans[ans.size() - i + pos[cur] - 1]);
        for(int i = pos[cur]; i < ans.size(); i ++)
            cout << ans[i] << " ";
        cout << "\n";
        return 0;
    }
    cout << "NO\n";
}
