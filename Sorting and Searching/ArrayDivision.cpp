#include <iostream>
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
using namespace std;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef long long ll;
typedef pair<ll, ll> pll;
#define max(n, m) ((n>m)?n:m)
#define min(n, m) ((n<m)?n:m)
#define f first
#define s second
 
ll n, k, idx = 0, mx = 0;
ll nums[200010];
ll bs(ll l, ll r)
{
    ll mid = (l + r) / 2, cnt = 1, cur = 0;
    if(l == r) return mid;
    for(int i = 0; i < n; i ++)
    {
        if(cur + nums[i] > mid)
        {
            cur = 0;
            cnt ++;
        }
        cur += nums[i];
    }
    if(cnt > k) return bs(mid + 1, r);
    return bs(l, mid);
}
int main()
{
    cin >> n >> k;
    for(int i = 0; i < n; i ++)
    {
        cin >> nums[i];
        mx = max(mx, nums[i]);
    }
    cout << bs(mx, 1000000000000000) << "\n";
}
