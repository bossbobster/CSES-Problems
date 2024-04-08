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
#include <regex>
#include <numeric>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
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
#define pi 3.14159265358979323846
//#define cin fin
//#define cout fout
//#define fin cin
//#define fout cout
#pragma GCC optimize("O1,O2,O3,Ofast,unroll-loops")

/*

     ._________.
     |_________|
   ---------------
  |_____• U •_____|
 -------------------
|___________________|


 */

struct chash
{
    const uint64_t C = ll(2e18*(3.14))+71;
    const int RANDOM = rand();
    ll operator()(ll x) const
    {
        return __builtin_bswap64((x^RANDOM)*C);
    }
};
const ll mod = 2000002853, p = 137;
ll pw[100010];
ll hsh[100010], cur[100010];
void hshs(string st, ll* hs)
{
    hs[0] = 1;
    for(int i = 0; i < (int)st.length(); i ++)
        hs[i + 1] = ((hs[i] * p) % mod + (ll)st[i]) % mod;
}
ll get(int a, int b)
{
    return (hsh[b + 1] - (hsh[a] * pw[b - a + 1]) % mod + mod) % mod;
}
bitset<100010> len;
gp_hash_table<int, int, chash> pos[100010];
int cnt[100010], tot[100010];
gp_hash_table<int, int, chash> qs;
int qm[500010];
string all[500010];
bitset<500010> ans;
int main()
{
    input();
    int n, k;
    string st;
    cin >> st >> k;
    n = (int)st.length();
    pw[0] = 1;
    for(int i = 1; i <= n; i ++)
        pw[i] = (pw[i - 1] * p) % mod;
    hshs(st, hsh);
    for(int i = 0; i < k; i ++)
    {
        cin >> all[i];
        if(all[i].length() > n) continue;
        len[all[i].length()] = 1;
        hshs(all[i], cur);
        int ln = (int)all[i].length();
        ll c = (cur[ln] - (cur[0] * pw[ln]) % mod + mod) % mod;
        if(qs.find(c) == qs.end())
        {
            qs[c] = i;
            qm[i] = i;
            pos[ln][c] = i;
            tot[ln]++;
        }
        else qm[i] = qs[c];
    }
    for(int l = 1; l <= n; l ++)
    {
        if(len[l])
        {
            for(int i = 0; i <= n-l; i ++)
            {
                int a = get(i, i+l-1);
                if(pos[l].find(a) != pos[l].end())
                {
                    ans[pos[l][a]] = 1, cnt[l]++;
                    pos[l].erase(a);
                    if(cnt[l] == tot[l]) break;
                }
            }
        }
    }
    for(int i = 0; i < k; i ++)
        cout << ((ans[qm[i]]==1)?"YES\n":"NO\n");
}
