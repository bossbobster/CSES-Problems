#include <iostream>
#include <string.h>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
#include <algorithm>
#include <math.h>
#include <cmath>
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
typedef pair<int, string> pis;
typedef pair<int, char> pic;
typedef pair<pii, int> piii;
typedef pair<double, double> pdd;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<ll, ll> pll;
typedef pair<int, ll> pil;
typedef pair<ull, ull> pull;
//#define max(n, m) ((n>m)?n:m)
//#define min(n, m) ((n<m)?n:m)
#define f first
#define s second
#define input() ios_base::sync_with_stdio(0);cin.tie(0);

int mod = 1000000007;
vector<int> adj[30];
int dp[1100000][21];
int main()
{
    input();
    int n, m, a, b;
    cin >> n >> m;
    for(int i = 0; i < m; i ++)
    {
        cin >> a >> b; a--; b--;
        adj[b].push_back(a);
    }
    dp[1][0] = 1;
    for(int i = 2; i < (1<<n); i ++)
        if(i & 1)
            for(int j = 1; j < n; j ++)
                if(i & (1<<j))
                    for(int it : adj[j])
                        if(i & (1<<it))
                            dp[i][j] = (dp[i][j] + dp[i ^ (1<<j)][it]) % mod;
    cout << dp[(1<<n)-1][n-1] << "\n";
}
