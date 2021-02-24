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
 
ll nums[200010];
ll pre[200010];
map<ll, ll> cnt;
ll mod(ll a, ll b)
{
    if(a < 0) return (b * (abs(a) / b + 1) + a) % b;
    return a % b;
}
int main()
{
    ll n, ans = 0;
    cin >> n;
    for(int i = 0; i < n; i ++)
    {
        cin >> nums[i];
        nums[i] = mod(nums[i], n);
        pre[i + 1] = mod((pre[i] + nums[i]), n);
    }
    cnt[0] ++;
    for(int i = 0; i < n; i ++)
    {
        ans += cnt[pre[i + 1]];
        cnt[pre[i + 1]] ++;
    }
    cout << ans << "\n";
}
