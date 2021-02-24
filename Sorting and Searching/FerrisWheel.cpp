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
 
set<int> nums;
map<int, int> cnt;
int main()
{
    int n, x, num, ans = 0, cur;
    set<int>::iterator other;
    cin >> n >> x;
    for(int i = 0; i < n; i ++)
    {
        cin >> num; nums.insert(num); cnt[num] ++;
    }
    while(!nums.empty())
    {
        cur = *nums.begin();
        other = nums.lower_bound(x - cur);
        if(other != nums.begin()) other --;
        if(cur == *other && cnt[cur] < 2) other ++;
        if(cur + *other > x) ans ++;
        ans ++;
        cnt[cur] --; cnt[*other] --;
        if(cnt[cur] == 0) nums.erase(cur);
        if(cnt[*other] == 0) nums.erase(*other);
    }
    cout << ans << "\n";
}
