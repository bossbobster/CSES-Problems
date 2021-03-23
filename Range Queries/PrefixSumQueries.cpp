#include <iostream>
#include <string.h>
#include <fstream>
#include <stdio.h>
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
//#include <ext/pb_ds/assoc_container.hpp>
//ulng namespace __gnu_pbds;
using namespace std;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef long long ll;
typedef pair<ll, ll> pll;
//#define max(n, m) ((n>m)?n:m)
//#define min(n, m) ((n<m)?n:m)
#define f first
#define s second

ll seg[1000010];
ll lazy[1000010];
ll nums[1000010];
ll arr[1000010];
void updateRec(int node, int l, int r, int lq, int rq, ll val) //current node, left val of node, right val of node, left val of update range, right val of update range (inclusive of both), value to add to range
{
    if(lazy[node]) //if there is pending lazy update on this node
    {
        seg[node] += lazy[node]; //update the range by adding val the correct amt of times
        if(l != r) //if not leaf node, store lazy updates for its children
        {
            lazy[node * 2 + 1] += lazy[node];
            lazy[node * 2 + 2] += lazy[node];
        }
        lazy[node] = 0;
    }
    if(l > rq || r < lq || l > r) return; //if update range not in current nodes range, return
    if(l >= lq && r <= rq) //if current node range completely inside of update range, update all
    {
        seg[node] += val;
        if(l != r) //if not leaf node, store lazy updates for its children with the update value
        {
            lazy[node * 2 + 1] += val;
            lazy[node * 2 + 2] += val;
        }
        return;
    }
    int mid = (l + r) / 2; //if current node range and update range overlap, recurse to both children
    updateRec(node * 2 + 1, l, mid, lq, rq, val);
    updateRec(node * 2 + 2, mid + 1, r, lq, rq, val);
    seg[node] = max(seg[node * 2 + 1], seg[node * 2 + 2]); //use children to update current
}
void update(int lq, int rq, ll val, int n) { updateRec(0, 0, n - 1, lq, rq, val); }
ll mxRec(int node, int l, int r, int lq, int rq)
{
    if(lazy[node]) //if there is pending lazy update on this node
    {
        seg[node] += lazy[node]; //update the range by adding val the correct amt of times
        if(l != r) //if not leaf node, store lazy updates for its children
        {
            lazy[node * 2 + 1] += lazy[node];
            lazy[node * 2 + 2] += lazy[node];
        }
        lazy[node] = 0;
    }
    if(l > rq || r < lq || l > r) return -2000000000000000000; //if update range not in current nodes range, return 0
    if(l >= lq && r <= rq) //if current node range completely inside of update range, add all from range to answer
        return seg[node];
    int mid = (l + r) / 2; //if current node range and update range overlap, recurse to both children and add them to answer
    return max(mxRec(node * 2 + 1, l, mid, lq, rq), mxRec(node * 2 + 2, mid + 1, r, lq, rq));
}
ll mx(int lq, int rq, int n) { if(lq == -1) return 0; return mxRec(0, 0, n-1, lq, rq); }
void makeRec(int node, int l, int r)
{
    if(l > r) return;
    if(l == r) { seg[node] = nums[l]; return; }
    int mid = (l + r) / 2;
    makeRec(node * 2 + 1, l, mid);
    makeRec(node * 2 + 2, mid + 1, r);
    seg[node] = max(seg[node * 2 + 1], seg[node * 2 + 2]);
}
void make(int n) { makeRec(0, 0, n-1); }
int main()
{
    int n, q, type, a, b;
    cin >> n >> q;
    cin >> nums[0]; arr[0] = nums[0];
    for(int i = 1; i < n; i ++)
    {
        cin >> nums[i]; arr[i] = nums[i];
        nums[i] += nums[i - 1];
    }
    make(n);
    for(int i = 0; i < q; i ++)
    {
        cin >> type >> a >> b;
        if(type == 2)
            cout << max((ll)0, mx(a-1, b-1, n) - mx(a-2, a-2, n)) << "\n";
        else
        {
            update(a-1, n-1, b - arr[a-1], n);
            arr[a-1] = b;
        }
    }
}
