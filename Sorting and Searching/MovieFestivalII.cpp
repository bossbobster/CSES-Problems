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

bool comp(pii p1, pii p2)
{
    if(p1.second == p2.second) return p1.first < p2.first;
    return p1.second < p2.second;
}
pii nums[200010];
multiset<int> r;
int main()
{
    int n, k, ans = 0;
    multiset<int>::iterator cur;
    cin >> n >> k;
    for(int i = 0; i < n; i ++)
        cin >> nums[i].f >> nums[i].s;
    sort(nums, nums + n, comp);
    for(int i = 0; i < k; i ++)
        r.insert(0);
    for(int i = 0; i < n; i ++)
    {
        if(nums[i].f < *r.begin()) continue;
        ans ++;
        r.insert(nums[i].s);
        cur = r.lower_bound(nums[i].f);
        if(cur == r.begin()) r.erase(cur);
        else r.erase(prev(cur));
    }
    cout << ans << "\n";
}
