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
int ap[200010];
int main()
{
    int n, m, k, idx1 = 0, idx2 = 0, ans = 0;
    cin >> n >> m >> k;
    for(int i = 0; i < n; i ++)
        cin >> nums[i];
    for(int i = 0; i < m; i ++)
        cin >> ap[i];
    sort(nums, nums + n); sort(ap, ap + m);
    while(idx1 < n && idx2 < m)
    {
        if(nums[idx1] > ap[idx2] + k) { idx2 ++; continue; }
        if(ap[idx2] > nums[idx1] + k) { idx1 ++; continue; }
        ans ++; idx1 ++; idx2 ++;
    }
    cout << ans << "\n";
}
