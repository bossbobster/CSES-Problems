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

int kmp[1000010], z[1000010];
int main()
{
    string st;
    int n, l = 0, r = 0, x;
    cin >> st;
    n = (int)st.length();
    for(int i = 1; i < n; i ++)
    {
        if(i > r)
        {
            for(l = r = i; r < n && st[r-l] == st[r]; r++){}
            r--;
            z[i] = r-l+1;
        }
        else
        {
            if(z[i-l] < r-i+1)
                z[i] = z[i-l];
            else
            {
                l = i;
                for(l = i; r < n && st[r-l] == st[r]; r++){}
                r--;
                z[i] = r-l+1;
            }
        }
    }
    kmp[0] = -1; kmp[1] = 0;
    for(int i = 1; i < st.length(); i ++)
    {
        x = kmp[i];
        while(x != -1 && st[x] != st[i])
            x = kmp[x];
        kmp[i+1] = x+1;
    }
    for(int i = 0; i < n; i ++)
        cout << z[i] << ((i==n-1)?"\n":" ");
    for(int i = 1; i <= n; i ++)
        cout << kmp[i] << ((i==n)?"\n":" ");
}
