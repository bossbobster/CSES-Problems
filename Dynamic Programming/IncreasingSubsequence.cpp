#include <iostream>
#include <fstream>
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
vector<int> dp;
int main()
{
    int n, ans = 0, change;
    cin >> n;
    for(int i = 0; i < n; i ++)
        cin >> nums[i];
    dp.push_back(nums[0]);
    for(int i = 0; i < n; i ++)
        dp.push_back(2000000000);
    for(int i = 1; i < n; i ++)
    {
        change = (int)(lower_bound(dp.begin(), dp.end(), nums[i]) - dp.begin());
        dp[change] = nums[i];
        ans = max(ans, change + 1);
    }
    cout << ans << "\n";
}
