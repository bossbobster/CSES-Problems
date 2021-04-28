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
#define input(x) ios_base::sync_with_stdio(x); cin.tie(x);

int n, q;
int nums[200010];
pii tree[1000010];
void update(int l, int r, int curIdx, int upIdx, int val)
{
    if(l == r)
    {
        tree[curIdx] = {val, val};
        nums[upIdx] = val;
        return;
    }
    int mid = (l + r) / 2;
    if(upIdx >= l && upIdx <= mid)
        update(l, mid, curIdx * 2 + 1, upIdx, val);
    else
        update(mid + 1, r, curIdx * 2 + 2, upIdx, val);
    tree[curIdx] = { min(tree[curIdx*2+1].f, tree[curIdx*2+2].f+mid+1-l), min(tree[curIdx*2+2].s, tree[curIdx*2+1].s+r-mid) };
}
int minR(int l, int r, int lq, int rq, int curIdx)
{
    if(lq == rq)
        return nums[lq];
    if(r < lq || l > rq)
        return 2000000000;
    if(lq <= l && rq >= r)
        return tree[curIdx].f+l-lq;
    int mid = (l + r) / 2;
    int n1 = minR(l, mid, lq, rq, curIdx*2+1), n2 = minR(mid+1, r, lq, rq, curIdx*2+2);
    return min(n1, n2);
}
int minL(int l, int r, int lq, int rq, int curIdx)
{
    if(lq == rq)
        return nums[lq];
    if(r < lq || l > rq)
        return 2000000000;
    if(lq <= l && rq >= r)
        return tree[curIdx].s+rq-r;
    int mid = (l + r) / 2;
    int n1 = minL(l, mid, lq, rq, curIdx*2+1), n2 = minL(mid+1, r, lq, rq, curIdx*2+2);
    return min(n1, n2);
}
void makeTree(int l, int r, int curIdx)
{
    if(l == r) { tree[curIdx] = {nums[l], nums[l]}; return; }
    int mid = (l + r) / 2;
    makeTree(l, mid, curIdx*2+1); makeTree(mid+1, r, curIdx*2+2);
    tree[curIdx] = { min(tree[curIdx*2+1].f, tree[curIdx*2+2].f+mid+1-l), min(tree[curIdx*2+2].s, tree[curIdx*2+1].s+r-mid) };
}
int main()
{
    int a, b, c, ans;
    input(0);
    cin >> n >> q;
    for(int i = 0; i < n; i ++)
        cin >> nums[i];
    makeTree(0, n-1, 0);
    while(q--)
    {
        cin >> a;
        if(a == 1)
        {
            cin >> b >> c; b--;
            update(0, n-1, 0, b, c);
        }
        else
        {
            cin >> b; b--;
            ans = nums[b];
            if(b != 0) ans = min(ans, minL(0, n-1, 0, b-1, 0)+1);
            if(b != n-1) ans = min(ans, minR(0, n-1, b+1, n-1, 0)+1);
            cout << ans << "\n";
        }
    }
}
