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

//const double eps = 0.1;
ld mid;
int n, k;
ll nums[3010], cur;
pldi dp[3010];
void bs(ll l, ll r)
{
//    mid = floor((l+r)/2.0)/10.0;
    mid = (l+r)/20.0;
    for(int i = 0; i <= n; i ++) dp[i] = {2e18, -1};
    dp[0] = {0, 0};
    for(int i = 1; i <= n; i ++)
    {
        cur = 0;
        for(int j = i-1; j >= 0; j --)
        {
            cur += nums[j];
            if(dp[j].f+cur*cur+mid < dp[i].f)
                dp[i] = {dp[j].f+cur*cur+mid, dp[j].s+1};
        }
    }
    if(l >= r) return;
    if(dp[n].s <= k) return bs(l, floor(mid*10));
    return bs(floor(mid*10)+1, r);
}
int main()
{
    input();
    cin >> n >> k;
    for(int i = 0; i < n; i ++)
        cin >> nums[i];
    n++;
    nums[n-1] = 0;
    bs(-1e17, 1e17);
    cout << (ll)round(dp[n].f-mid*k) << '\n';
}
