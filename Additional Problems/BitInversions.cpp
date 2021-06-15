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

struct node
{
    pii l, r;
    int ans;
};

string st;
node seg[1000010];
void update(int l, int r, int curIdx, int upIdx)
{
    if(l == r)
    {
        if(st[l] == '1') st[l] = '0';
        else st[l] = '1';
        seg[curIdx].l = {1, st[l]-'0'}; seg[curIdx].r = {1, st[l]-'0'}; seg[curIdx].ans = 1;
        return;
    }
    int mid = (l + r) / 2;
    if(upIdx >= l && upIdx <= mid)
        update(l, mid, curIdx * 2 + 1, upIdx);
    else
        update(mid + 1, r, curIdx * 2 + 2, upIdx);
    int ln = curIdx*2+1, rn = curIdx*2+2;
    seg[curIdx].ans = max(seg[ln].ans, seg[rn].ans);
    if(seg[ln].r.s == seg[rn].l.s) seg[curIdx].ans = max(seg[curIdx].ans, seg[ln].r.f + seg[rn].l.f);
    if(seg[ln].l == seg[ln].r && seg[ln].l.f == mid-l+1)
    {
        if(seg[rn].l.s == seg[ln].r.s) seg[curIdx].l = {seg[ln].l.f + seg[rn].l.f, seg[ln].l.s};
        else seg[curIdx].l = seg[ln].l;
    }
    else seg[curIdx].l = seg[ln].l;
    if(seg[rn].l == seg[rn].r && seg[rn].l.f == r-mid)
    {
        if(seg[rn].l.s == seg[ln].r.s) seg[curIdx].r = {seg[rn].l.f + seg[ln].r.f, seg[rn].l.s};
        else seg[curIdx].r = seg[rn].r;
    }
    else seg[curIdx].r = seg[rn].r;
}
void makeTree(int l, int r, int curIdx)
{
    if(l == r) { seg[curIdx].l = {1, st[l]-'0'}; seg[curIdx].r = {1, st[l]-'0'}; seg[curIdx].ans = 1; return; }
    int mid = (l + r) / 2;
    makeTree(l, mid, curIdx * 2 + 1); makeTree(mid + 1, r, curIdx * 2 + 2);
    int ln = curIdx*2+1, rn = curIdx*2+2;
    seg[curIdx].ans = max(seg[ln].ans, seg[rn].ans);
    if(seg[ln].r.s == seg[rn].l.s) seg[curIdx].ans = max(seg[curIdx].ans, seg[ln].r.f + seg[rn].l.f);
    if(seg[ln].l == seg[ln].r && seg[ln].l.f == mid-l+1)
    {
        if(seg[rn].l.s == seg[ln].r.s) seg[curIdx].l = {seg[ln].l.f + seg[rn].l.f, seg[ln].l.s};
        else seg[curIdx].l = seg[ln].l;
    }
    else seg[curIdx].l = seg[ln].l;
    if(seg[rn].l == seg[rn].r && seg[rn].l.f == r-mid)
    {
        if(seg[rn].l.s == seg[ln].r.s) seg[curIdx].r = {seg[rn].l.f + seg[ln].r.f, seg[rn].l.s};
        else seg[curIdx].r = seg[rn].r;
    }
    else seg[curIdx].r = seg[rn].r;
}
int main()
{
    input();
    int m, a;
    cin >> st >> m;
    makeTree(0, (int)st.length()-1, 0);
    while(m--)
    {
        cin >> a; a--;
        update(0, (int)st.length()-1, 0, a);
        cout << seg[0].ans << ((m==0)?"\n":" ");
    }
}
