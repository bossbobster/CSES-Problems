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
 
int dp[100010];
pii nums[1010];
int main()
{
    int n, c, ans = 0;
    cin >> n >> c;
    for(int i = 0; i < n; i ++)
        cin >> nums[i].f;
    for(int i = 0; i < n; i ++)
        cin >> nums[i].s;
    for(int i = 1; i <= c; i ++)
        dp[i] = -2000000000;
    for(int i = 0; i < n; i ++)
        for(int j = c; j >= 0; j --)
            if(j - nums[i].f >= 0)
                if(dp[j - nums[i].f] >= 0)
                    dp[j] = max(dp[j], dp[j - nums[i].f] + nums[i].s);
    for(int i = 0; i <= c; i ++)
        ans = max(ans, dp[i]);
    cout << ans << "\n";
}
