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

int mod = 1000000007;
long long exp(long long base, long long power)
{
    if(power == 0) return 1;
    if(power == 1) return base;
    long long cur = exp(base, power / 2);
    long long ans = (cur * cur) % mod;
    if(power % 2 == 1) ans = (ans * base) % mod;
    return ans % mod;
}
ll fac[1000010];
int main()
{
    int n;
    ll a, b, ans;
    cin >> n;
    fac[0] = 1;
    for(int i = 1; i < 1000001; i ++)
        fac[i] = (fac[i-1] * i) % mod;
    for(int i = 0; i < n; i ++)
    {
        cin >> a >> b;
        ans = exp(fac[b], mod-2);
        ans = (ans * fac[a]) % mod;
        ans = (exp(fac[a-b], mod-2) * ans) % mod;
        cout << ans << "\n";
    }
}
