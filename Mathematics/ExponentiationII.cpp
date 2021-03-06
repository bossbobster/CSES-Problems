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
typedef pair<pii, int> piii;
typedef long long ll;
typedef pair<ll, ll> pll;
//#define max(n, m) ((n>m)?n:m)
//#define min(n, m) ((n<m)?n:m)
#define f first
#define s second

long long exp(long long base, long long power, int mod)
{
    if(power == 0) return 1;
    if(power == 1) return base;
    long long cur = exp(base, power / 2, mod);
    long long ans = (cur * cur) % mod;
    if(power % 2 == 1) ans = (ans * base) % mod;
    return ans % mod;
}

int main()
{
    int n;
    ll a, b, c, tmp;
    cin >> n;
    for(int i = 0; i < n; i ++)
    {
        cin >> a >> b >> c;
        tmp = exp(b, c, 1000000006);
        cout << exp(a, tmp, 1000000007) << "\n";
    }
}
