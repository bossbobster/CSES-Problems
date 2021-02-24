#include <iostream>
#include <iomanip>
#include <algorithm>
#include <math.h>
#include <vector>
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
 
pll nums[200010];
int main()
{
    ll n, ans = 0, total = 0;
    cin >> n;
    for(int i = 0; i < n; i ++)
        cin >> nums[i].f >> nums[i].s;
    sort(nums, nums + n);
    for(int i = 0; i < n; i ++)
    {
        total += nums[i].f;
        ans += nums[i].s - total;
    }
    cout << ans << "\n";
}
