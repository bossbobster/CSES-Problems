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
#include <bitset>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <complex>
#include <valarray>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef pair<int, int> pii;
typedef pair<int, string> pis;
typedef pair<string, string> pss;
typedef pair<int, char> pic;
typedef pair<pii, int> piii;
typedef pair<double, double> pdd;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<ll, ll> pll;
typedef pair<int, ll> pil;
typedef pair<ull, ull> pull;
typedef complex<double> cd;
//#define max(n, m) ((n>m)?n:m)
//#define min(n, m) ((n<m)?n:m)
#define f first
#define s second
#define input() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

struct chash
{
    const uint64_t C = ll(2e18*(3.14))+71;
    const int RANDOM = rand();
    ll operator()(ll x) const
    {
        return __builtin_bswap64((x^RANDOM)*C);
    }
};

int n;
const int mod = 1000000007;
int nums[200010], sorted[200010];
ll bit[200010];
ll sum(int idx)
{
    ll ans = 0;
    idx ++;
    while(idx > 0)
    {
        ans = (ans + bit[idx]) % mod;
        idx -= idx & (-idx);
    }
    return ans;
}
void update(int idx, int val)
{
    idx ++;
    while(idx <= n)
    {
        bit[idx] = (bit[idx] + val) % mod;
        idx += idx & (-idx);
    }
}
gp_hash_table<int, int, chash> m;
int main()
{
    input();
    ll cur = 0, ans = 0;
    cin >> n;
    for(int i = 0; i < n; i ++)
        cin >> nums[i], sorted[i] = nums[i];
    sort(sorted, sorted+n);
    for(int i = 0; i < n; i ++)
        m[sorted[i]] = i;
    for(int i = 0; i < n; i ++)
        nums[i] = m[nums[i]];
    for(int i = 0; i < n; i ++)
    {
        cur = (sum(nums[i]-1)+1) % mod;
        ans = (ans+cur) % mod;
        update(nums[i], cur);
    }
    cout << ans << "\n";
}
