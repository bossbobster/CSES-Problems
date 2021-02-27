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

int dp[130000];
int main()
{
    int n, sum;
    cin >> n;
    if(n % 4 == 2 || n % 4 == 1) { cout << 0 << "\n"; return 0; }
    sum = n * (n + 1) / 2;
    for(int i = 0; i < sum; i ++)
        dp[i] = 0;
    dp[0] = 1;
    for(int i = 1; i < n; i ++)
        for(int j = sum; j >= i; j --)
            dp[j] = (dp[j] + dp[j - i]) % 1000000007;
    cout << dp[sum / 2] << "\n";
}
