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
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
using namespace std;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef long long ll;
typedef pair<ll, ll> pll;
#define max(n, m) ((n>m)?n:m)
#define min(n, m) ((n<m)?n:m)
#define f first
#define s second

ll nums[30];
pll dp[1100000][21];
pll best[1100000];
int main()
{
    ll n, x;
    pll cur;
    cin >> n >> x;
    for(int i = 0; i < n; i ++)
        cin >> nums[i];
    for(int i = 0; i < (1 << n); i ++)
        for(int j = 0; j < n; j ++)
            dp[i][j] = best[i] = {2000000000, 0};
    for(int i = 0; i < n; i ++)
        dp[0][i].f = dp[0][i].s = best[0].f = best[0].s = 0;
    for(int i = 0; i < n; i ++)
        dp[(1 << i)][i] = {0, nums[i]};
    for(int i = 1; i < (1 << n); i ++)
        for(int j = 0; j < n; j ++)
            if(i & (1 << j))
            {
                cur = best[i ^ (1 << j)];
                cur.s += nums[j];
                if(cur.s / x > 1)
                    cur = {cur.f + 2, 0};
                else if(cur.s == x)
                    cur = {cur.f + 1, 0};
                else if(cur.s / x == 1)
                    cur = {cur.f + 1, nums[j]};
                else {}
                if(cur.f < dp[i][j].f || (cur.f == dp[i][j].f && cur.s < dp[i][j].s))
                    dp[i][j] = cur;
                if(dp[i][j].f < best[i].f || (dp[i][j].f == best[i].f && dp[i][j].s < best[i].s))
                    best[i] = dp[i][j];
            }
    cout << best[(1 << n) - 1].f + min(1, best[(1 << n) - 1].s) << "\n";
}
