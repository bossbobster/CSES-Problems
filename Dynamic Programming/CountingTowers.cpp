#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <math.h>
#include <vector>
#include <unordered_set>
using namespace std;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
#define max(n, m) ((n>m)?n:m)
#define min(n, m) ((n<m)?n:m)
#define f first
#define s second
 
long long dp[1000010][2]; // [i][0] = up to index i, disconnected, [i][1] = up to index i, connected
int mod = 1000000007;
int main()
{
    int t, n;
    cin >> t;
    for(int i = 0; i < 1000001; i ++)
        dp[i][0] = dp[i][1] = 0;
    dp[0][0] = dp[0][1] = 1;
    for(int i = 1; i < 1000001; i ++)
    {
        dp[i][0] += (dp[i - 1][0] * 4) % mod;
        dp[i][0] += (dp[i - 1][1]) % mod;
        dp[i][1] += (dp[i - 1][0]) % mod;
        dp[i][1] += (dp[i - 1][1] * 2) % mod;
        dp[i][0] = dp[i][0] % mod; dp[i][1] = dp[i][1] % mod;
    }
    while(t --)
    {
        cin >> n;
        cout << (dp[n - 1][0] + dp[n - 1][1]) % mod << "\n";
    }
}
