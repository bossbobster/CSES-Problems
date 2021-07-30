#include <iostream>
#include <string.h>
#include <random>
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
#include <complex>
#include <valarray>
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
using namespace std;
typedef pair<int, int> pii;
typedef pair<int, string> pis;
typedef pair<string, string> pss;
typedef pair<int, char> pic;
typedef pair<pii, int> piii;
typedef pair<double, double> pdd;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<ll, ll> pll;
typedef pair<int, ll> pil;
typedef pair<ull, ull> pull;
typedef complex<double> cd;
//#define max(n, m) ((n>m)?n:m)
//#define min(n, m) ((n<m)?n:m)
#define f first
#define s second
#define input() ios_base::sync_with_stdio(0);cin.tie(0);

ld dp[610][110];
int main()
{
    input();
    int n, a, b;
    cin >> n >> a >> b;
    dp[0][0] = 1;
    for(int i = 1; i <= 6*n; i ++)
        for(int j = 1; j <= n; j ++)
            for(int k = 1; k <= 6; k ++)
                if(i-k >= 0)
                    dp[i][j] += dp[i-k][j-1];
    ld ans = 0, div = 1;
    for(int i = 0; i < n; i ++)
        div *= 6.0;
    for(int i = a; i <= b; i ++)
        ans += dp[i][n] / div;
    cout << fixed << setprecision(6) << ans << "\n";
}
