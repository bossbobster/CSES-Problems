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
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<ll, ll> pll;
typedef pair<ull, ull> pull;
//#define max(n, m) ((n>m)?n:m)
//#define min(n, m) ((n<m)?n:m)
#define f first
#define s second

struct st
{
    ll tot, l, r, mx;
};

int n, m;
ll nums[200010];
st tree[800010];
void update(int l, int r, int curIdx, int upIdx, ll val)
{
    if(l == r)
    {
        tree[curIdx] = {val, val, val, val};
        nums[upIdx] = val;
        return;
    }
    int mid = (l + r) / 2;
    if(upIdx >= l && upIdx <= mid)
        update(l, mid, curIdx * 2 + 1, upIdx, val);
    else
        update(mid + 1, r, curIdx * 2 + 2, upIdx, val);
    tree[curIdx].tot = tree[curIdx*2+1].tot + tree[curIdx*2+2].tot;
    tree[curIdx].l = max(tree[curIdx*2+1].l, tree[curIdx*2+1].tot + tree[curIdx*2+2].l);
    tree[curIdx].r = max(tree[curIdx*2+2].tot + tree[curIdx*2+1].r, tree[curIdx*2+2].r);
    tree[curIdx].mx = max({tree[curIdx*2+1].mx, tree[curIdx*2+2].mx, tree[curIdx*2+1].r + tree[curIdx*2+2].l});
}
ll maxQ(int l, int r, int lq, int rq, int curIdx)
{
    if(lq == rq)
        return nums[lq];
    if(r < lq || l > rq)
        return -2000000000000000000;
    if(lq <= l && rq >= r)
        return tree[curIdx].mx;
    int mid = (l + r) / 2;
    if(rq <= mid) return maxQ(l, mid, lq, rq, curIdx * 2 + 1);
    if(lq > mid) return maxQ(mid + 1, r, lq, rq, curIdx * 2 + 2);
    return max(maxQ(l, mid, lq, rq, curIdx * 2 + 1), maxQ(mid + 1, r, lq, rq, curIdx * 2 + 2));
}
void makeTree(int l, int r, int curIdx)
{
    if(l == r)
    {
        tree[curIdx] = {nums[l], nums[l], nums[l], nums[l]};
        return;
    }
    int mid = (l + r) / 2;
    makeTree(l, mid, curIdx * 2 + 1); makeTree(mid + 1, r, curIdx * 2 + 2);
    tree[curIdx].tot = tree[curIdx*2+1].tot + tree[curIdx*2+2].tot;
    tree[curIdx].l = max(tree[curIdx*2+1].l, tree[curIdx*2+1].tot + tree[curIdx*2+2].l);
    tree[curIdx].r = max(tree[curIdx*2+2].tot + tree[curIdx*2+1].r, tree[curIdx*2+2].r);
    tree[curIdx].mx = max({tree[curIdx*2+1].mx, tree[curIdx*2+2].mx, tree[curIdx*2+1].r + tree[curIdx*2+2].l});
}
int main()
{
    int a; ll b;
    cin >> n >> m;
    for(int i = 0; i < n; i ++) cin >> nums[i];
    makeTree(0, n-1, 0);
    for(int i = 0; i < m; i ++)
    {
        cin >> a >> b; a--;
        update(0, n-1, 0, a, b);
        cout << max((ll)0, maxQ(0, n-1, 0, n-1, 0)) << "\n";
    }
}
