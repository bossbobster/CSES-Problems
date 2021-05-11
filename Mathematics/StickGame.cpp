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
#pragma GCC optimize ("O2")
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
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
#define max(n, m) ((n>m)?n:m)
//#define min(n, m) ((n<m)?n:m)
#define f first
#define s second
#define input(x) ios_base::sync_with_stdio(x); cin.tie(x);

bitset<1000010> dp;
int nums[1000010];
int main()
{
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < k; i ++)
        cin >> nums[i];
    dp[1] = true;
    cout << 'W';
    for(int i = 2; i <= n; i ++)
    {
        for(int j = 0; j < k; j ++)
            if(i - nums[j] >= 0)
                dp[i] = max(dp[i], !dp[i-nums[j]]);
        cout << ((dp[i])?'W':'L');
    }
    cout << "\n";
}
