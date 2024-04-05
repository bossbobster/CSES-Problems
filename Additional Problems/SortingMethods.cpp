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

int nums[200010], bit[200010], nx[200010];
bitset<200010> vis;
int n;
int sum(int idx)
{
    int ans = 0;
    idx ++;
    while(idx > 0)
    {
        ans += bit[idx];
        idx -= idx & (-idx);
    }
    return ans;
}
void up(int idx, int val)
{
    idx ++;
    while(idx <= n)
    {
        bit[idx] += val;
        idx += idx & (-idx);
    }
}
vector<int> dp;
int main()
{
    input();
    cin >> n;
    for(int i = 0; i < n; i ++)
        cin >> nums[i];
    // method 1: counting inversions
    ll ans1 = 0;
    for(int i = n-1; i >= 0; i --)
    {
        ans1 += sum(nums[i]-1);
        up(nums[i]-1, 1);
    }
    // method 2: count cycles
    ll ans2 = 0;
    for(int i = 0; i < n; i ++)
    {
        if(vis[i]) continue;
        int sz = 0, cur = i;
        while(!vis[cur])
        {
            vis[cur] = 1; sz++;
            cur = nums[cur]-1;
        }
        ans2 += sz-1;
    }
    // method 3: LIS
    ll ans3 = 0, change;
    dp.push_back(nums[0]);
    for(int i = 0; i < n; i ++)
        dp.push_back(2000000000);
    for(int i = 1; i < n; i ++)
    {
        change = (int)(lower_bound(dp.begin(), dp.end(), nums[i]) - dp.begin());
        dp[change] = nums[i];
        ans3 = max(ans3, change + 1);
    }
    ans3 = n-ans3;
    // method 4: kinda like sleepy cow sorting (or whatever that bronze problem is called)
    ll ans4 = 0;
    int idx = -1, num = n;
    for(int i = 0; i < n; i ++)
        if(nums[i] == n)
        {
            idx = i;
            break;
        }
    for(int i = idx; i >= 0; i --)
        if(nums[i] == num)
        {
            num--;
        }
    ans4 = num;
    // print out all of them
    cout << ans1 << ' ' << ans2 << ' ' << ans3 << ' ' << ans4 << '\n';
}
