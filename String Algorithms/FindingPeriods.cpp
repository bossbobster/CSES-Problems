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

string st;
int n;
const int mod = 1000000009, p = 9973;
ll pw[1000010];
ll hsh[1000010];
void hshs()
{
    hsh[0] = 1;
    for(int i = 0; i < n; i ++)
        hsh[i + 1] = ((hsh[i] * p) % mod + (ll)st[i]) % mod;
}
ll get(int a, int b)
{
    return (hsh[b + 1] - (hsh[a] * pw[b - a + 1]) % mod + mod) % mod;
}
vector<int> ans;
int main()
{
    input();
    cin >> st;
    n = (int)st.length();
    bool good;
    pw[0] = 1;
    for(int i = 1; i <= n; i ++)
        pw[i] = (pw[i - 1] * p) % mod;
    hshs();
    for(int i = 0; i < n; i ++)
    {
        good = true;
        for(int j = i+1; j < n; j += i+1)
            if(get(0, min(n-1-j, i)) != get(j, min(n-1, j+i)))
            {
                good = false;
                break;
            }
        if(good) ans.push_back(i+1);
    }
    for(int i = 0; i < ans.size(); i ++)
        cout << ans[i] << ((i==ans.size()-1)?"\n":" ");
}
