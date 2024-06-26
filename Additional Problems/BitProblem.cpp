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

int nums[200010], cnt[1100010], dp1[1100010], dp2[1100010];
int main()
{
    input();
    int n;
    cin >> n;
    for(int i = 0; i < n; i ++)
        cin >> nums[i], cnt[nums[i]] ++;
    const int lg = 20, mx = 1048575;
    // x | y = x (y is in x)
    for(int i = 0; i < (1<<lg); i ++)
        dp1[i] = cnt[i];
    for(int j = 0; j < lg; j ++)
        for(int i = 0; i < (1<<lg); i ++)
            if(i&(1<<j))
                dp1[i] += dp1[i^(1<<j)];
    // x & y = x (x is in y, which is the same as ~y is in ~x)
    for(int i = 0; i < (1<<lg); i ++)
        dp2[i] = cnt[mx^i];
    for(int j = 0; j < lg; j ++)
        for(int i = 0; i < (1<<lg); i ++)
            if(i&(1<<j))
                dp2[i] += dp2[i^(1<<j)];
    // x & y ≠ 0 (n - (y is in ~x), so
    for(int i = 0; i < n; i ++)
        cout << dp1[nums[i]] << ' ' << dp2[mx^nums[i]] << ' ' << n-dp1[mx^nums[i]] << '\n';
}
