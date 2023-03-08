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
#include <chrono>
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

struct query
{
    //type 1 is insert, 0 is delete
    int type, a, b;
};
struct op
{
    int* where; //pointer to value
    int old, c; //old value, component change
};

vector<query> qs;
struct dsu
{
    int par[100010];
    int siz[100010];
    op cur;
    int ans = 0;
    stack<op> st;
    dsu(int size)
    {
        for(int i = 0; i <= size; i ++)
            par[i] = i, siz[i] = 1;
        ans = size;
    }
    //find root of n
    int root(int n)
    {
        //no path compression
        return ((par[n]==n)?n:root(par[n]));
    }
    //return true if n and m are in the same CC
    bool con(int n, int m)
    {
        return (root(n) == root(m));
    }
    //connect n and m
    void un(int n, int m)
    {
        n = root(n); m = root(m);
        if(n == m) return;
        if(siz[n] < siz[m])
            swap(n, m);
        st.push({par+m, par[m], 1});
        st.push({siz+n, siz[n], 0});
        ans --;
        par[m] = n;
        siz[n] += siz[m];
    }
    //undo until a particular stack size
    void rollback(int szz)
    {
        while(st.size() > szz)
        {
            cur = st.top(); st.pop();
            *cur.where = cur.old;
            ans += cur.c;
        }
    }
};
map<ll, int> pre;
map<ll, vector<pii>> arr;
vector<pii> seg[800010];
dsu d(10);
int n, m, q, type;
void updateRec(int node, int l, int r, int lq, int rq, pii val)
{
    if(l > rq || r < lq || l > r) return;
    if(l >= lq && r <= rq)
    {
        seg[node].push_back(val);
        return;
    }
    int mid = (l+r)/2;
    updateRec(node*2+1, l, mid, lq, rq, val); updateRec(node*2+2, mid+1, r, lq, rq, val);
}
void update(int lq, int rq, pii val) { updateRec(0, 0, m+q-1, lq, rq, val); }
int ansans[100010];
void dfs(int node, int l, int r)
{
    int curSz = (int)d.st.size();
    for(auto it : seg[node])
    {
        d.un(it.f, it.s);
    }
    if(l == r)
    {
        if(l >= m-1)
            ansans[l-m+1] = d.ans;
        d.rollback(curSz);
        return;
    }
    int mid = (l+r)/2;
    dfs(node*2+1, l, mid); dfs(node*2+2, mid+1, r);
    d.rollback(curSz);
}
int main()
{
    input();
    ll a, b;
    cin >> n >> m >> q;
    for(int i = 0; i < m; i ++)
    {
        cin >> a >> b; a--; b--;
        if(a > b) swap(a, b);
        pre[a*n+b] = i+1;
    }
    for(int i = 0; i < q; i ++)
    {
        cin >> type >> a >> b; a--; b--; type = 2-type;
        if(a > b) swap(a, b);
        if(type == 1) pre[a*n+b] = i+m+1;
        else if(pre[a*n+b] != 0) update(pre[a*n+b]-1, i+m-1, {a, b}), pre[a*n+b] = 0;
    }
    for(auto it : pre)
        if(it.s != 0)
            update(it.s-1, q+m-1, {it.f/n, it.f%n});
    d = dsu(n);
    dfs(0, 0, m+q-1);
    for(int i = 0; i <= q; i ++)
        cout << ansans[i] << ((i==q)?'\n':' ');
}
