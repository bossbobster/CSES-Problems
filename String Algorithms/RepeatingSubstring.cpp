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
#pragma GCC optimize("O1,O2,O3,Ofast,unroll-loops")

int len[200010];
int n, idxAll, num, pp;
int cnt[30], idx[30];
piii all[200010];
string st;
int pre[300010][22];
const ll mod = 1000000007, p = 31;
ll pw[200010], hsh[200010];
void hshs()
{
    hsh[0] = 1;
    for(int i = 0; i < n; i ++)
        hsh[i+1] = ((hsh[i]*p) % mod + (ll)st[i]) % mod;
}
ll get(int a, int b)
{
    return (hsh[b+1] - (hsh[a]*pw[b-a+1])%mod+mod) % mod;
}
void suf()
{
    for(int i = 0; i < n; i ++)
        cnt[st[i]-'a'] ++;
    idx[0] = -1;
    for(int i = 1; i < 27; i ++)
        idx[i] = idx[i-1] + min(1, cnt[i-1]);
    for(int i = 0; i < n; i ++)
        pre[i][0] = idx[st[i]-'a'+1];
    pp = log2(n);
    for(int i = 1; i <= pp; i ++)
    {
        idxAll = 0;
        for(int j = 0; j < n; j ++)
            all[idxAll++] = {{pre[j][i-1], pre[j+(1<<(i-1))][i-1]}, j};
        sort(all, all+n);
        num = 0;
        for(int j = 0; j < n; j ++)
            pre[all[j].s][i] = (j != 0 && all[j].f.f == all[j-1].f.f && all[j].f.s == all[j-1].f.s)?pre[all[j-1].s][i]:num++;
    }
}
set<pii> srt1;
vector<int> sorted;
ll lcp(int i1, int i2)
{
    if(i1 == -1 || i2 == -1) return 0;
    int mx = min(len[i1], len[i2]);
    int ppp = log2(mx), eq1 = i1, eq2 = i2;
    while(ppp > -1)
    {
        if(get(eq1, eq1+(1<<ppp)-1) == get(eq2, eq2+(1<<ppp)-1)) eq1 = eq1+(1<<ppp), eq2 = eq2+(1<<ppp);
        ppp--;
    }
    return min((ll)mx, (ll)(eq1-i1));
}
ll ans = 0, whc = -1;
int main()
{
    cin >> st;
    n = (int)st.length();
    for(int i = 0; i < n; i ++)
        len[i] = n-i;
    suf();
    for(int i = 0; i < n; i ++)
        srt1.insert({pre[i][pp], i});
    for(auto it : srt1)
        sorted.push_back(it.s);
    pw[0] = 1;
    for(int i = 1; i <= 2*n; i ++)
        pw[i] = (pw[i-1]*p)%mod;
    hshs();
    int prr = -1;
    for(auto it : sorted)
    {
        ll num = lcp(it, prr);
        if(num > ans)
        {
            whc = it;
            ans = num;
        }
        prr = it;
    }
    if(whc == -1) cout << "-1\n";
    else cout << st.substr(whc, ans) << '\n';
}
