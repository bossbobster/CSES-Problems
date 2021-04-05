#include <iostream>
#include <string.h>
#include <fstream>
#include <stdio.h>
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
typedef pair<string, string> pss;
typedef pair<pii, int> piii;
typedef pair<string, int> psi;
typedef long long ll;
typedef pair<ll, ll> pll;
//#define max(n, m) ((n>m)?n:m)
//#define min(n, m) ((n<m)?n:m)
#define f first
#define s second

ll mod = 1000000007;
ll dp[1000010];
int main()
{
    ll n;
    cin >> n;
    dp[1] = 0;
    dp[2] = 1;
    if(n <= 2) { cout << dp[n] << "\n"; return 0; }
    for(int i = 3; i <= n; i ++)
        dp[i] = ((dp[i - 1] + dp[i - 2]) * (i-1)) % mod;
    cout << dp[n] << "\n";
}
