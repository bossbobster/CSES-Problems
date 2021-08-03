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
#define input() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

ll gcd(ll l1, ll l2)
{
    if(l1 < l2) swap(l1, l2);
    if(l2 == 0) return l1;
    return gcd(l2, l1 % l2);
}
const int mod = 1000000007;
ll ex(ll base, ll power)
{
    ll ans = 1;
    while(power)
    {
        if(power&1) ans = (ans * base) % mod;
        base = (base * base) % mod;
        power /= 2;
    }
    return ans;
}
int main()
{
    input();
    int n, m;
    ll ans = 0;
    cin >> n >> m;
    for(int i = 0; i < n; i ++)
        ans = (ans + ex(m, gcd(i, n)) * ex(n, mod-2)) % mod;
    cout << ans << "\n";
}
