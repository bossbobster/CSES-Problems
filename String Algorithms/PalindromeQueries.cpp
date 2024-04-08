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


const ll mod = 2000002853, p = 137, pp = 1503651780;
ll pw[200010], inv[200010];
int n, m;
ll bit[200010], rbit[200010];
ll sum(ll *arr, int idx)
{
    ll ans = 0;
    idx ++;
    while(idx > 0)
    {
        ans = (ans+arr[idx])%mod;
        idx -= idx & (-idx);
    }
    return ans;
}
void up(ll *arr, int idx, ll val)
{
    idx ++;
    while(idx <= n+1)
    {
        arr[idx] = (arr[idx]+val)%mod;
        idx += idx & (-idx);
    }
}
void hshs(string st, ll* bt)
{
    for(int i = 0; i < (int)st.length(); i ++)
        up(bt, i+1, (pw[i]*st[i])%mod);
//        hs[i+1] = (hs[i] + pw[i]*st[i]) % mod;
}
ll get(int a, int b, ll* bt)
{
//    return ((hs[b + 1]-hs[a]+mod) * inv[a]) % mod;
    ll r = sum(bt, b+1), l = sum(bt, a);
    return ((r-l+mod) * inv[a]) % mod;
}
int main()
{
    input();
    string st, rev;
    cin >> n >> m >> st;
    rev = st; reverse(rev.begin(), rev.end());
    pw[0] = 1;
    for(int i = 1; i <= n; i ++)
        pw[i] = (pw[i - 1] * p) % mod;
    inv[0] = 1;
    for(int i = 1; i <= n; i ++)
        inv[i] = (inv[i - 1] * pp) % mod;
    hshs(st, bit); hshs(rev, rbit);
    int t, a, b; char c;
    while(m--)
    {
        cin >> t >> a; a--;
        if(t == 2)
        {
            cin >> b; b--;
            ll l = get(a, b, bit), r = get(n-b-1, n-a-1, rbit);
            if(l == r) cout << "YES\n";
            else cout << "NO\n";
        }
        else
        {
            cin >> c;
            ll cur = (pw[a]*st[a])%mod, ne = (pw[a]*c)%mod;
            ne = (ne-cur+mod)%mod;
            up(bit, a+1, ne);
            cur = (pw[n-a-1]*st[a])%mod; ne = (pw[n-a-1]*c)%mod;
            ne = (ne-cur+mod)%mod;
            up(rbit, n-a, ne);
            st[a] = c;
        }
    }
}
