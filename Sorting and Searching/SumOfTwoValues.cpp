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
 
pii nums[200010];
int main()
{
    int n, target;
    int other;
    cin >> n >> target;
    if(n == 1) { cout << "IMPOSSIBLE\n"; return 0; }
    for(int i = 0; i < n; i ++)
    {
        cin >> nums[i].f;
        nums[i].s = i;
    }
    sort(nums, nums + n);
    for(int i = 0; i < n; i ++)
    {
        other = lower_bound(nums + i + 1, nums + n, pii(target - nums[i].f, 0)) - nums;
        if(nums[other].f + nums[i].f == target)
        {
            cout << nums[i].s + 1 << " " << nums[other].s + 1 << "\n";
            return 0;
        }
    }
    cout << "IMPOSSIBLE" << "\n";
}
