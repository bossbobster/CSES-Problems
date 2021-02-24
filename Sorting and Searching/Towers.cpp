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
 
int nums[200010];
set<int> towers;
map<int, int> cnt;
int main()
{
    int n, ans = 0;
    cin >> n;
    for(int i = 0; i < n; i ++)
        cin >> nums[i];
    for(int i = 0; i < n; i ++)
    {
        if(towers.upper_bound(nums[i]) != towers.end())
        {
            cnt[nums[i]] ++;
            towers.insert(nums[i]);
            cnt[*towers.upper_bound(nums[i])] --;
            if(cnt[*towers.upper_bound(nums[i])] == 0) towers.erase(*towers.upper_bound(nums[i]));
        }
        else
        {
            ans ++;
            cnt[nums[i]] ++;
            towers.insert(nums[i]);
        }
    }
    cout << ans << "\n";
}
