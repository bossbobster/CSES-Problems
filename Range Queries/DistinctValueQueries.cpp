#include <iostream>
#include <string.h>
#include <fstream>
#include <stdio.h>
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
//ulng namespace __gnu_pbds;
using namespace std;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef long long ll;
typedef pair<ll, ll> pll;
//#define max(n, m) ((n>m)?n:m)
//#define min(n, m) ((n<m)?n:m)
#define f first
#define s second

int sum(int arr[], int idx)
{
    int ans = 0;
    idx ++;
    while(idx > 0)
    {
        ans += arr[idx];
        idx -= idx & (-idx);
    }
    return ans;
}
void update(int arr[], int idx, int val, int size)
{
    if(idx == -1) return;
    idx ++;
    while(idx <= size)
    {
        arr[idx] += val;
        idx += idx & (-idx);
    }
}
struct chash { /// use most bits rather than just the lowest ones
    const uint64_t C = ll(2e18*(3.14))+71; // large odd number
    const int RANDOM = rand(); // random 32-bit number
    ll operator()(ll x) const {
        // https://gcc.gnu.org/onlinedocs/gcc/Other-Builtins.html
        return __builtin_bswap64((x^RANDOM)*C);
    }
};
struct st
{
    int a, b, idx;
    const bool operator<(const st& other) const
    {
        if(b == other.b) return a < other.a;
        return b < other.b;
    }
};
int nums[200010];
int last[200010];
st qs[200010];
int ans[200010];
int bit[200010];
unordered_map<int, int, chash> m;
int main()
{
    int n, q, cur = 0;
    cin >> n >> q;
    for(int i = 0; i < n; i ++)
        last[i] = -1;
    for(int i = 0; i < n; i ++)
    {
        cin >> nums[i];
        m[nums[i]] = i;
    }
    for(int i = 0; i < n; i ++) nums[i] = m[nums[i]];
    for(int i = 0; i < q; i ++)
    {
        cin >> qs[i].a >> qs[i].b;
        qs[i].a --; qs[i].b --;
        qs[i].idx = i;
    }
    sort(qs, qs + q);
    for(int i = 0; i < n; i ++)
    {
        update(bit, last[nums[i]], -1, n);
        update(bit, i, 1, n);
        last[nums[i]] = i;
        while(qs[cur].b == i)
        {
            ans[qs[cur].idx] = sum(bit, i) - sum(bit, qs[cur].a - 1);
            cur ++;
        }
    }
    for(int i = 0; i < q; i ++)
        cout << ans[i] << "\n";
}
