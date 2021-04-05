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
ll cur = 1, d = 1;
long long exp(long long base, long long power)
{
    if(power == 0) return 1;
    if(power == 1) return base;
    long long cur = exp(base, power / 2);
    long long ans = (cur * cur) % mod;
    if(power % 2 == 1) ans = (ans * base) % mod;
    return ans % mod;
}
int main()
{
    int n, m;
    cin >> n >> m; // n + m - 1 choose m
    for(int i = n + m - 1; i > n - 1; i --)
        cur = (cur * i) % mod;
    for(int i = 2; i <= m; i ++)
        d = (d * i) % mod;
    cout << (exp(d, mod-2) * cur) % mod << "\n";
}
