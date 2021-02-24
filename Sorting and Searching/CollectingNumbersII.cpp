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
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
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
gp_hash_table<int, int> pos;
int main()
{
    int n, m, pre = 2000000000, cur, ans = 0, a, b;
    cin >> n >> m;
    for(int i = 0; i < n; i ++)
    {
        cin >> nums[i];
        pos[nums[i]] = i;
    }
    for(int i = 1; i <= n; i ++)
    {
        if(pos[i] < pre) ans ++;
        pre = pos[i];
    }
    for(int i = 0; i < m; i ++)
    {
        cin >> a >> b;
        a --; b --;
        pre = 0;
        if(nums[a] != 1 && pos[nums[a]] < pos[nums[a] - 1]) pre ++;
        if(nums[a] != n && pos[nums[a] + 1] < pos[nums[a]]) pre ++;
        if(nums[b] != 1 && pos[nums[b]] < pos[nums[b] - 1] && nums[a] != nums[b] - 1) pre ++;
        if(nums[b] != n && pos[nums[b] + 1] < pos[nums[b]] && nums[a] != nums[b] + 1) pre ++;
        pos[nums[a]] = b; pos[nums[b]] = a;
        swap(nums[a], nums[b]);
        cur = 0;
        if(nums[a] != 1 && pos[nums[a]] < pos[nums[a] - 1]) cur ++;
        if(nums[a] != n && pos[nums[a] + 1] < pos[nums[a]]) cur ++;
        if(nums[b] != 1 && pos[nums[b]] < pos[nums[b] - 1] && nums[a] != nums[b] - 1) cur ++;
        if(nums[b] != n && pos[nums[b] + 1] < pos[nums[b]] && nums[a] != nums[b] + 1) cur ++;
        ans += cur - pre;
        cout << ans << "\n";
    }
}
