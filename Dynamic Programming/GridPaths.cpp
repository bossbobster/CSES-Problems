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
 
int dp[1010][1010];
string board[1010];
int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i ++)
        cin >> board[i];
    if(board[0][0] != '*') dp[0][0] = 1;
    for(int i = 1; i < n; i ++)
    {
        if(board[i][0] == '*')
            dp[i][0] = 0;
        else
            dp[i][0] = dp[i - 1][0];
    }
    for(int i = 1; i < n; i ++)
    {
        if(board[0][i] == '*')
            dp[0][i] = 0;
        else
            dp[0][i] = dp[0][i - 1];
    }
    for(int i = 1; i < n; i ++)
        for(int j = 1; j < n; j ++)
            if(board[i][j] == '.')
                dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % 1000000007;
    cout << dp[n - 1][n - 1] << "\n";
}
