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

int dp[510][510];
int main()
{
    int n, m;
    cin >> n >> m;
    if(n > m) swap(n, m);
    for(int i = 0; i <= m; i ++)
        for(int j = 0; j <= m; j ++)
            dp[i][j] = 1000000000;
    for(int i = 1; i <= m; i ++)
        dp[i][i] = 0;
    for(int i = 1; i <= n; i ++)
        for(int j = i + 1; j <= m; j ++)
        {
            for(int k = 1; k <= i / 2; k ++)
                dp[i][j] = min(dp[i][j], dp[k][j] + dp[i - k][j] + 1);
            for(int k = 1; k <= j / 2; k ++)
                dp[i][j] = min(dp[i][j], dp[min(k, i)][max(k, i)] + dp[min(i, j - k)][max(i, j - k)] + 1);
        }
    cout << dp[n][m] << "\n";
}
