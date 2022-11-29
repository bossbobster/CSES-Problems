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
#include <array>
#include <bitset>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <complex>
#include <valarray>
#include <memory>
#include <cassert>
using namespace std;
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
typedef pair<int, int> pii;
typedef pair<int, string> pis;
typedef pair<pis, string> piss;
typedef pair<int, short> pish;
typedef pair<string, string> pss;
typedef pair<int, char> pic;
typedef pair<pii, int> piii;
typedef pair<double, double> pdd;
typedef pair<double, int> pdi;
typedef pair<float, float> pff;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef unsigned short ushort;
typedef pair<uint, uint> puint;
typedef pair<ll, ll> pll;
typedef pair<pll, ll> plll;
typedef pair<pll, ld> plld;
typedef pair<ld, int> pldi;
typedef pair<int, ll> pil;
typedef pair<ll, int> pli;
typedef pair<ull, ull> pull;
typedef pair<ld, ld> pld;
typedef complex<double> cd;
//#define max(n, m) ((n>m)?n:m)
//#define min(n, m) ((n<m)?n:m)
#define f first
#define s second
#define input() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
//#define eps 1e-8
//#define eps2 1e-15
#define leni(x) sizeof(x)/sizeof(int)
#define v(i,j,k) for(i=j;i<k;i++)
//#define cin fin
//#define cout fout
#pragma GCC optimize("O1,O2,O3,Ofast,unroll-loops")

int b[2000010];
inline int md(int a, int&b)
{
    if(a >= b) a-=b;
    return a;
}
int main()
{
    input();
    int n;
    string st;
    cin >> st;
    n = (int)st.length();
    memset(b, -1, sizeof(b));
    int k = 0, idx;
    for(int i = 1; i < 2*n; i ++)
    {
        idx = b[i-k-1];
        while(idx != -1 && st[md(i,n)] != st[md(k+idx+1,n)])
        {
            if(st[md(i,n)] < st[md(k+idx+1,n)])
                k = i-idx-1;
            idx = b[idx];
        }
        if(idx == -1 && st[md(i,n)] != st[md(k,n)])
        {
            if(st[md(i,n)] < st[md(k,n)])
                k = i;
            b[i-k] = -1;
        }
        else
            b[i-k] = idx+1;
    }
    int len = n-k;
    cout << st.substr(k, len) << st.substr(0, n-len) << '\n';
}
