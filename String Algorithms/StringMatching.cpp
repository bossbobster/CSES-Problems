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
typedef pair<int, string> pis;
typedef pair<int, char> pic;
typedef pair<pii, int> piii;
typedef long long ll;
typedef pair<ll, ll> pll;
//#define max(n, m) ((n>m)?n:m)
//#define min(n, m) ((n<m)?n:m)
#define f first
#define s second

string st, pat;
int n, m;
ll mod = 1000000007, p = 7;
ll pw[2000010];
ll hsh[2000010];
void hshs()
{
    hsh[0] = 1;
    for(int i = 0; i < (int)st.length(); i ++)
        hsh[i + 1] = ((hsh[i] * p) % mod + (ll)st[i]) % mod;
}
ll get(int a, int b)
{
    return (hsh[b + 1] - (hsh[a] * pw[b - a + 1]) % mod + mod) % mod;
}
int main()
{
    int ans = 0;
    st.reserve(2000000); pat.reserve(1000000);
    cin >> st >> pat;
    n = (int)st.length(); m = (int)pat.length();
    st += pat;
    pw[0] = 1;
    for(int i = 1; i <= st.length(); i ++)
        pw[i] = (pw[i - 1] * p) % mod;
    hshs();
    for(int i = 0; i <= n - m; i ++)
        if(get(i, i + m - 1) == get(n, n + m - 1))
            ans ++;
    cout << ans << "\n";
}
