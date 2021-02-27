#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <math.h>
#include <vector>
#include <stack>
#include <queue>
#include <bitset>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
using namespace std;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef long long ll;
typedef pair<ll, ll> pll;
#define max(n, m) ((n>m)?n:m)
#define f first
#define s second

int nums[200010];
void update(int* tree, int l, int r, int curIdx, int upIdx, int val)
{
    if(l == r)
    {
        tree[curIdx] = val;
        nums[upIdx] = val;
        return;
    }
    int mid = (l + r) / 2;
    if(upIdx >= l && upIdx <= mid)
        update(tree, l, mid, curIdx * 2 + 1, upIdx, val);
    else
        update(tree, mid + 1, r, curIdx * 2 + 2, upIdx, val);
    tree[curIdx] = min(tree[curIdx * 2 + 1], tree[curIdx * 2 + 2]);
}
int minQ(int* tree, int l, int r, int lq, int rq, int curIdx)
{
    if(lq == rq)
        return nums[lq];
    if(r < lq || l > rq)
        return 2000000000;
    if(lq <= l && rq >= r)
        return tree[curIdx];
    int mid = (l + r) / 2;
    if(rq <= mid) return minQ(tree, l, mid, lq, rq, curIdx * 2 + 1);
    if(lq > mid) return minQ(tree, mid + 1, r, lq, rq, curIdx * 2 + 2);
    return min(minQ(tree, l, mid, lq, rq, curIdx * 2 + 1), minQ(tree, mid + 1, r, lq, rq, curIdx * 2 + 2));
}
int makeTreeRec(int* tree, int l, int r, int curIdx)
{
    if(l == r)
    {
        tree[curIdx] = nums[l];
        return tree[curIdx];
    }
    int mid = (l + r) / 2;
    tree[curIdx] = min(makeTreeRec(tree, l, mid, curIdx * 2 + 1), makeTreeRec(tree, mid + 1, r, curIdx * 2 + 2));
    return tree[curIdx];
}
int* makeTree(int n)
{
    int size = 2 * (int)pow(2, (int)ceil(log2(n))) + 5;
    int* tree = new int[size];
    makeTreeRec(tree, 0, n - 1, 0);
    return tree;
}
int main()
{
    int n, q, a, b, c;
    cin >> n >> q;
    for(int i = 0; i < n; i ++)
        cin >> nums[i];
    int *seg = makeTree(n);
    for(int i = 0; i < q; i ++)
    {
        cin >> a >> b >> c;
        if(a == 1)
            update(seg, 0, n - 1, 0, b - 1, c);
        else
            cout << minQ(seg, 0, n - 1, b - 1, c - 1, 0) << "\n";
    }
}
