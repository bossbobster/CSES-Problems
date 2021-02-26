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
    int n;
    cin >> n;
    dp[0] = 1;
    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= 6; j ++)
            if(i - j >= 0)
                dp[i] = (dp[i] + dp[i - j]) % 1000000007;
    cout << dp[n] << "\n";
}
