#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <math.h>
#include <vector>
#include <stack>
#include <queue>
#include <bitset>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
using namespace std;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef long long ll;
typedef pair<ll, ll> pll;
//#define max(n, m) ((n>m)?n:m)
//#define min(n, m) ((n<m)?n:m)
#define f first
#define s second
 
struct chash { /// use most bits rather than just the lowest ones
    const uint64_t C = ll(2e18*(3.14))+71; // large odd number
    const int RANDOM = rand(); // random 32-bit number
    ll operator()(ll x) const {
        // https://gcc.gnu.org/onlinedocs/gcc/Other-Builtins.html
        return __builtin_bswap64((x^RANDOM)*C);
    }
};
 
int sz;
ll tre[800010];
void makeTree(ll nums[])
{
    for(int i = 0; i < sz; i ++)
        tre[sz + i] = nums[i];
    for(int i = sz - 1; i > 0; -- i)
        tre[i] = max(tre[i << 1], tre[i << 1 | 1]);
}
void update(int idx, ll val)
{
    tre[idx + sz] = val;
    idx += sz;
    for(int i = idx; i > 1; i >>= 1)
        tre[i >> 1] = max(tre[i], tre[i ^ 1]);
}
ll maxQ(int l, int r) // inclusive l, exclusive r
{
    ll ans = 0;
    for(l += sz, r += sz; l < r; l >>= 1, r >>= 1)
    {
        if(l & 1)
            ans = max(ans, tre[l ++]);
        if(r & 1)
            ans = max(ans, tre[-- r]);
    }
    return ans;
}
struct st
{
    ll a, b, p;
    const bool operator<(const st& other) const
    {
        return a < other.a;
    }
};
st nums[200010];
ll coo[400010];
unordered_set<ll, chash> cooo;
unordered_map<ll, int, chash> hsh;
ll dp[200010];
int main()
{
    int n, cnt = 0;
    ll ans = 0;
    cin >> n;
    for(int i = 0; i < n; i ++)
    {
        cin >> nums[i].a >> nums[i].b >> nums[i].p;
        cooo.insert(nums[i].a); cooo.insert(nums[i].b);
    }
    for(auto cur : cooo) { coo[cnt] = cur; cnt ++; }
    sort(coo, coo + cnt); int cnt2 = 1;
    for(int i = 0; i < cnt; i ++) { hsh[coo[i]] = cnt2; cnt2 ++; }
    for(int i = 0; i < n; i ++) { nums[i].a = hsh[nums[i].a]; nums[i].b = hsh[nums[i].b]; }
    sort(nums, nums + n);
    sz = (int)cooo.size() + 1;
    makeTree(tre);
    for(int i = 0; i < n; i ++)
    {
        dp[i] = maxQ(0, (int)nums[i].a) + nums[i].p;
        if(dp[i] > ans) ans = dp[i];
        if(dp[i] > tre[nums[i].b + sz])
            update((int)nums[i].b, dp[i]);
        else
            update((int)nums[i].b, tre[nums[i].b + sz]);
    }
    cout << ans << "\n";
}
