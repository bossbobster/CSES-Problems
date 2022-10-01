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

int n, lg, m, m2, k;
double theta;
pdd omega, mult, t, u;
const double pi = 3.1415926535897932384626433;
bool inv;
uint bitR(uint x)
{
    int n = 0;
    for (int i = 0; i < lg; i++)
    {
        n <<= 1;
        n |= (x & 1);
        x >>= 1;
    }
    return n;
}
void fft(vector<pdd> &p)
{
    for(int i = 1; i <= lg; i ++)
    {
        m = 1<<i; m2 = m>>1;
        theta = pi*2/m*(inv?-1:1), omega = {1,0}, mult = {cos(theta), sin(theta)};
        for(int j = 0; j < m2; j ++)
        {
            for(int l = j; l < k; l += m)
            {
                t = {p[l+m2].f*omega.f-p[l+m2].s*omega.s, p[l+m2].f*omega.s+p[l+m2].s*omega.f};
                u = p[l];
                p[l] = {t.f+u.f, t.s+u.s};
                if(inv)
                    p[l].f /= 2, p[l].s /= 2;
                p[l+m2] = {u.f-t.f, u.s-t.s};
                if(inv)
                    p[l+m2].f /= 2, p[l+m2].s /= 2;
            }
            omega = {omega.f*mult.f-omega.s*mult.s, omega.f*mult.s+omega.s*mult.f};
        }
    }
}
vector<int> a, b;
int main()
{
    input();
    int n, m, ogk, rev;
    cin >> n >> m; k = n+m-1; ogk = k;
    while(log2(k) - floor(log2(k)) > 0.000001) k++;
    a.resize(k); b.resize(k);
    for(int i = 0; i < n; i ++)
        cin >> a[i];
    for(int i = 0; i < m; i ++)
        cin >> b[m-i-1];
    vector<pdd> fa, fb, fa1, fb1;
    for(int i = 0; i < a.size(); i ++)
        fa1.push_back({a[i],0});
    for(int i = 0; i < b.size(); i ++)
        fb1.push_back({b[i],0});
    lg = log2(k); fa.resize(k); fb.resize(k);
    for(uint i = 0; i < k; i ++)
    {
        rev = bitR(i);
        fa[i] = fa1[rev]; fb[i] = fb1[rev];
    }
    inv = false;
    fft(fa); fft(fb);
    for(int i = 0; i < k; i ++)
        fa[i] = {fa[i].f*fb[i].f-fa[i].s*fb[i].s, fa[i].f*fb[i].s+fa[i].s*fb[i].f};
    vector<pdd> faF; faF.resize(k);
    for(uint i = 0; i < k; i ++)
        rev = bitR(i), faF[i] = fa[rev];
    inv = true;
    fft(faF);
    for(int i = 0; i < ogk; i ++)
        cout << (ll)round(abs(faF[i].f)) << ((i==ogk-1)?'\n':' ');
}
