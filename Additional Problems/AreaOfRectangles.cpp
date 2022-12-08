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

const int mx = 2000010, add = 1000000;
struct rect
{
    int x, y1, y2, t;
    const bool operator<(const rect& other) const
    {
        return x < other.x;
    }
};
int n;
rect nums[200010];
pii seg[8000010];
int lazy[8000010];
void updateRec(int node, int l, int r, int lq, int rq, int val)
{
    if(lazy[node])
    {
        seg[node].f += lazy[node];
        if(l != r)
        {
            lazy[node*2+1] += lazy[node];
            lazy[node*2+2] += lazy[node];
        }
        lazy[node] = 0;
    }
    if(l > rq || r < lq || l > r) return;
    if(l >= lq && r <= rq)
    {
        seg[node].f += val;
        if(l != r)
        {
            lazy[node*2+1] += val;
            lazy[node*2+2] += val;
        }
        return;
    }
    int mid = (l+r)/2;
    updateRec(node*2+1, l, mid, lq, rq, val); updateRec(node*2+2, mid+1, r, lq, rq, val);
    if(seg[node*2+1].f < seg[node*2+2].f)
        seg[node] = seg[node*2+1];
    else if(seg[node*2+1].f > seg[node*2+2].f)
        seg[node] = seg[node*2+2];
    else seg[node] = {seg[node*2+1].f, seg[node*2+1].s+seg[node*2+2].s};
}
void update(int lq, int rq, int val) { updateRec(0, 0, mx-1, lq, rq, val); }
int countRec(int node, int l, int r, int lq, int rq)
{
    if(lazy[node])
    {
        seg[node].f += lazy[node];
        if(l != r)
        {
            lazy[node*2+1] += lazy[node];
            lazy[node*2+2] += lazy[node];
        }
        lazy[node] = 0;
    }
    if(l > rq || r < lq || l > r) return 0;
    if(l >= lq && r <= rq)
        return seg[node].s;
    int mid = (l+r)/2;
    return countRec(node*2+1, l, mid, lq, rq) + countRec(node*2+2, mid+1, r, lq, rq);
}
int count(int lq, int rq) { return countRec(0, 0, mx-1, lq, rq); }
void makeRec(int node, int l, int r)
{
    if(l > r) return;
    if(l == r) { seg[node] = {0, 1}; return; }
    int mid = (l+r)/2;
    makeRec(node*2+1, l, mid); makeRec(node*2+2, mid+1, r);
    if(seg[node*2+1].f < seg[node*2+2].f)
        seg[node] = seg[node*2+1];
    else if(seg[node*2+1].f > seg[node*2+2].f)
        seg[node] = seg[node*2+2];
    else seg[node] = {seg[node*2+1].f, seg[node*2+1].s+seg[node*2+2].s};
}
void make() { makeRec(0, 0, mx-1); }
int main()
{
    input();
    cin >> n;
    for(int i = 0; i < n; i ++)
    {
        cin >> nums[i*2].x >> nums[i*2].y1 >> nums[i*2+1].x >> nums[i*2].y2;
        nums[i*2].y2 --;
        nums[i*2+1].y1 = nums[i*2].y1; nums[i*2+1].y2 = nums[i*2].y2;
        nums[i*2].x += add; nums[i*2].y1 += add; nums[i*2].y2 += add;
        nums[i*2+1].x += add; nums[i*2+1].y1 += add; nums[i*2+1].y2 += add;
        nums[i*2].t = 1; //add
        nums[i*2+1].t = -1; //remove
    }
    sort(nums, nums+n*2);
    make();
    int pre = add;
    ll ans = 0;
    for(int i = 0; i < 2*n; i ++)
    {
        ll a = (mx-count(0, mx-1)), b = (nums[i].x-pre);
        ans += a*b;
        pre = nums[i].x;
        update(nums[i].y1, nums[i].y2, nums[i].t);
    }
    cout << ans << '\n';
}
