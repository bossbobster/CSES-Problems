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
#pragma GCC optimize ("O2")
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
using namespace std;
typedef pair<int, int> pii;
typedef pair<int, string> pis;
typedef pair<int, char> pic;
typedef pair<pii, int> piii;
typedef pair<double, double> pdd;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<ll, ll> pll;
typedef pair<int, ll> pil;
typedef pair<ull, ull> pull;
//#define max(n, m) ((n>m)?n:m)
//#define min(n, m) ((n<m)?n:m)
#define f first
#define s second
#define input() ios_base::sync_with_stdio(0);cin.tie(0);

ll seg[1000010];
ll lazy[1000010];
ll cnt[1000010];
ll nums[1000010];
void updateRec(int node, ll l, ll r, int lq, int rq, ll val)
{
    ll mid = (l + r) / 2;
    if(cnt[node] || lazy[node])
    {
        seg[node] += (lazy[node] * (r-l+1)) + ((r-l+1) * (r-l+2) * cnt[node] / 2);
        if(l != r)
        {
            lazy[node * 2 + 1] += lazy[node]; cnt[node*2+1] += cnt[node];
            lazy[node * 2 + 2] += lazy[node] + (mid+1 - l) * cnt[node]; cnt[node*2+2] += cnt[node];
        }
        lazy[node] = cnt[node] = 0;
    }
    if(l > rq || r < lq || l > r) return;
    if(l >= lq && r <= rq)
    {
        val += l - lq;
        seg[node] += val * (r - l + 1) + ((r-l+1) * (r-l+2) / 2);
        if(l != r)
        {
            lazy[node * 2 + 1] += val; cnt[node*2+1] ++;
            lazy[node * 2 + 2] += val + mid+1 - l; cnt[node*2+2] ++;
        }
        return;
    }
    updateRec(node * 2 + 1, l, mid, lq, rq, val);
    updateRec(node * 2 + 2, mid + 1, r, lq, rq, val);
    seg[node] = seg[node * 2 + 1] + seg[node * 2 + 2];
}
void update(int lq, int rq, int val, int n) { updateRec(0, 0, n - 1, lq, rq, val); }
ll sumRec(int node, ll l, ll r, int lq, int rq)
{
    ll mid = (l + r) / 2;
    if(cnt[node] || lazy[node])
    {
        seg[node] += (lazy[node] * (r-l+1)) + ((r-l+1) * (r-l+2) * cnt[node] / 2);
        if(l != r)
        {
            lazy[node * 2 + 1] += lazy[node]; cnt[node*2+1] += cnt[node];
            lazy[node * 2 + 2] += lazy[node] + (mid+1 - l) * cnt[node]; cnt[node*2+2] += cnt[node];
        }
        lazy[node] = cnt[node] = 0;
    }
    if(l > rq || r < lq || l > r) return 0;
    if(l >= lq && r <= rq)
        return seg[node];
    return sumRec(node * 2 + 1, l, mid, lq, rq) + sumRec(node * 2 + 2, mid + 1, r, lq, rq);
}
ll sum(int lq, int rq, int n) { return sumRec(0, 0, n-1, lq, rq); }
void makeRec(int node, int l, int r)
{
    if(l > r) return;
    if(l == r) { seg[node] = nums[l]; return; }
    int mid = (l + r) / 2;
    makeRec(node * 2 + 1, l, mid);
    makeRec(node * 2 + 2, mid + 1, r);
    seg[node] = seg[node * 2 + 1] + seg[node * 2 + 2];
}
void make(int n) { makeRec(0, 0, n-1); }
int main()
{
    input();
    int n, q, a, b, type;
    cin >> n >> q;
    for(int i = 0; i < n; i ++)
        cin >> nums[i];
    make(n);
    while(q--)
    {
        cin >> type >> a >> b; a--; b--;
        if(type == 1)
            update(a, b, 0, n);
        else
            cout << sum(a, b, n) << "\n";
    }
}
