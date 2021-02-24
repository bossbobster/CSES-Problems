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
 
pii nums[5010];
int main()
{
    int n, target;
    cin >> n >> target;
    if(n < 3) { cout << "IMPOSSIBLE\n"; return 0; }
    for(int i = 0; i < n; i ++)
    {
        cin >> nums[i].f;
        nums[i].s = i;
    }
    sort(nums, nums + n);
    for(int i = 0; i < n - 2; i ++)
    {
        for(int j = i + 1; j < n - 1; j ++)
        {
            
            int idx = (int)(lower_bound(nums + j + 1, nums + n, pii(target - nums[i].f - nums[j].f, 0)) - nums);
            if(idx == i || idx == j || idx >= n) continue;
            if(nums[i].f + nums[j].f + nums[idx].f == target)
            {
                cout << nums[i].s + 1 << " " << nums[j].s + 1 << " " << nums[idx].s + 1 << "\n";
                return 0;
            }
        }
    }
    cout << "IMPOSSIBLE\n";
}
