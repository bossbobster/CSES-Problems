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
#define max(n, m) ((n>m)?n:m)
//#define min(n, m) ((n<m)?n:m)
#define f first
#define s second

int mod = 1000000007;
ll sum(ll from, ll to)
{
    to %= mod; from %= mod;
    return ((to * (to + 1) / 2) - (from * (from + 1) / 2)) % mod;
}

int main()
{
    ll n, ans = 0, cur;
    cin >> n;
    if(n == 1) { cout << "1\n"; return 0; }
    if(n == 2) { cout << "4\n"; return 0; }
    if(n == 3) { cout << "8\n"; return 0; }
    for(int i = 1; i <= sqrt(n); i ++)
    {
        ans = (ans + i * (n / i)) % mod;
        cur = sum(sqrt(n), n/i) % mod;
        ans = (ans + cur) % mod;
    }
    cout << ans << "\n";
}
