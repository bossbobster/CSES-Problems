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
 
int nums[200010];
set<int> vals;
map<int, int> cnt;
int main()
{
    int n, k, idx = 0;
    ll ans = 0;
    cin >> n >> k;
    for(int i = 0; i < n; i ++)
        cin >> nums[i];
    for(int i = 0; i < n; i ++)
    {
        while(vals.size() <= k && idx <= n)
        {
            vals.insert(nums[idx]);
            cnt[nums[idx]] ++;
            idx ++;
        }
        ans += idx - i - 1;
        cnt[nums[i]] --;
        if(cnt[nums[i]] == 0) vals.erase(nums[i]);
    }
    cout << ans << "\n";
}
