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

ll nums[5010];
ll dp[5010][5010];
ll pre[5010];
ll sum(int a, int b)
{
    return pre[b + 1] - pre[a];
}
int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i ++)
    {
        cin >> nums[i];
        pre[i + 1] = pre[i] + nums[i];
    }
    for(int i = 0; i < n; i ++)
        dp[i][1] = nums[i];
    for(int i = 2; i <= n; i ++)
        for(int j = 0; j < n - i + 1; j ++)
            dp[j][i] = sum(j, j + i - 1) - min(dp[j][i - 1], dp[j + 1][i - 1]);
    cout << dp[0][n] << "\n";
}
