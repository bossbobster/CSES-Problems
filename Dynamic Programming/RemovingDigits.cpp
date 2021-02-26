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
 
int dp[1000010];
int main()
{
    int n, cur;
    cin >> n;
    for(int i = 1; i <= n; i ++)
        dp[i] = 1000000000;
    for(int i = 1; i <= n; i ++)
    {
        cur = i;
        while(cur != 0)
        {
            dp[i] = min(dp[i], dp[i - (cur % 10)] + 1);
            cur /= 10;
        }
    }
    cout << dp[n] << "\n";
}
