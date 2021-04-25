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
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<ll, ll> pll;
typedef pair<ull, ull> pull;
//#define max(n, m) ((n>m)?n:m)
//#define min(n, m) ((n<m)?n:m)
#define f first
#define s second

ll mod = 1000000007, ans;
map<ll, ll> m;
ll fib(ll n)
{
    if(m.find(n) != m.end()) return m[n];
    if(n % 2 == 0)
    {
        ll k = n/2;
        ans = ((fib(k-1) * 2 + fib(k)) * fib(k)) % mod;
        m[n] = ans;
        return ans;
    }
    else
    {
        ll k = n/2+1;
        ans = (fib(k) * fib(k) + fib(k-1) * fib(k-1)) % mod;
        m[n] = ans;
        return ans;
    }
}
int main()
{
    ll n;
    m[0] = 0; m[1] = 1;
    cin >> n;
    cout << fib(n) << "\n";
}
