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

ll nums[400010], pre[400010];
pii nx[200010][20];
pii find(int st, int to, int mx)
{
    int cur = 0, steps = 0;
    for(int i = 19; i >= 0; i --)
        if(cur+nx[st][i].s < mx || (cur+nx[st][i].s == mx && nx[st][i].f <= to))
            cur += nx[st][i].s, st = nx[st][i].f, steps += (1<<i);
    return {st, steps};
}
int main()
{
    input();
    int n;
    ll k;
    cin >> n >> k;
    for(int i = 0; i < n; i ++)
        cin >> nums[i];
    for(int i = n; i < 2*n; i ++)
        nums[i] = nums[i-n];
    for(int i = 0; i < 2*n; i ++)
        pre[i+1] = pre[i]+nums[i];
    if(pre[n] <= k)
    {
        cout << "1\n";
        return 0;
    }
    for(int i = 0; i < n; i ++)
    {
        int idx = (int)(upper_bound(pre+i+1, pre+2*n+1, k+pre[i])-pre-1);
        nx[i][0] = {((idx>=n)?idx-n:idx), ((idx>=n)?1:0)};
    }
    for(int i = 1; i < 20; i ++)
        for(int j = 0; j < n; j ++)
            nx[j][i] = {nx[nx[j][i-1].f][i-1].f, nx[j][i-1].s+nx[nx[j][i-1].f][i-1].s};
    int ans = 2000000000;
    for(int i = 0; i < n; i ++) //assume that a subarray starts here
    {
        pii p = find(i, -1, 1); //find min number of steps until the sum loops back around
        pii p2 = find(p.f, i-1, 1); //now loop and go until i
        ans = min(ans, p.s+p2.s+1);
    }
    cout << ans << '\n';
}
