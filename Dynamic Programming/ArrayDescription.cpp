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

int dp[100010][110];
int nums[100010];
int main()
{
    int n, m, ans = 0;
    cin >> n >> m;
    for(int i = 0; i < n; i ++)
        cin >> nums[i];
    for(int i = 1; i <= m; i ++)
        if(nums[0] == 0 || nums[0] == i)
            dp[0][i] = 1;
    for(int i = 1; i < n; i ++)
        for(int j = 1; j <= m; j ++)
            if(nums[i] == 0 || nums[i] == j)
                dp[i][j] = ((((dp[i - 1][j - 1] + dp[i - 1][j]) % 1000000007) + dp[i - 1][j + 1]) % 1000000007);
    for(int i = 1; i <= m; i ++)
        ans = (ans + dp[n - 1][i]) % 1000000007;
    cout << ans << "\n";
}
