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
 
pii og[200010];
struct st
{
    int a, b, idx;
    const bool operator<(const st &other) const
    {
        if(a == other.a && b == other.b) return og[idx].f < og[other.idx].f;
        if(a == other.a) return b < other.b;
        return a < other.a;
    }
};
st nums[400010];
int ans[200010];
set<int> pos;
int main()
{
    int n, mx = 0;
    cin >> n;
    for(int i = 0; i < n; i ++)
    {
        cin >> nums[i * 2].a >> nums[i * 2 + 1].a;
        og[i].f = nums[i * 2].a; og[i].s = nums[i * 2 + 1].a;
        nums[i * 2].b = 0; nums[i * 2 + 1].b = 1;
        nums[i * 2].idx = i; nums[i * 2 + 1].idx = i;
    }
    n *= 2;
    for(int i = 1; i <= n; i ++) pos.insert(i);
    sort(nums, nums + n);
    for(int i = 0; i < n; i ++)
    {
        if(nums[i].b == 0)
        {
            mx = max(mx, *pos.begin());
            ans[nums[i].idx] = *pos.begin();
            pos.erase(pos.begin());
        }
        else
        {
            pos.insert(ans[nums[i].idx]);
        }
    }
    cout << mx << "\n";
    for(int i = 0; i < n / 2; i ++)
        cout << ans[i] << " ";
    cout << "\n";
}
