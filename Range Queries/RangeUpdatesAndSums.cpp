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
pll lazy[1000010];
ll nums[1000010];
ll arr[1000010];
void updateRec(int node, int l, int r, int lq, int rq, ll val, int type) //current node, left val of node, right val of node, left val of update range, right val of update range (inclusive of both), value to add to range
{
    if(lazy[node].s) //if there is pending lazy update on this node
    {
        if(lazy[node].s == 1) seg[node] += lazy[node].f * (r - l + 1); //update the range by adding val the correct amt of times
        else seg[node] = lazy[node].f * (r - l + 1);
        if(l != r) //if not leaf node, store lazy updates for its children
        {
            if(lazy[node].s == 1) { lazy[node * 2 + 1].f += lazy[node].f; lazy[node * 2 + 2].f += lazy[node].f; }
            else { lazy[node * 2 + 1].f = lazy[node].f; lazy[node * 2 + 2].f = lazy[node].f; }
            lazy[node * 2 + 1].s = lazy[node * 2 + 2].s = max(lazy[node * 2 + 1].s, lazy[node].s);
        }
        lazy[node] = {0, 0};
    }
    if(l > rq || r < lq || l > r) return; //if update range not in current nodes range, return
    if(l >= lq && r <= rq) //if current node range completely inside of update range, update all
    {
        if(type == 1) seg[node] += val * (r - l + 1);
        else seg[node] = val * (r - l + 1);
        if(l != r) //if not leaf node, store lazy updates for its children with the update value
        {
            if(type == 1) { lazy[node * 2 + 1].f += val; lazy[node * 2 + 2].f += val; }
            else { lazy[node * 2 + 1].f = val; lazy[node * 2 + 2].f = val; }
            lazy[node * 2 + 1].s = lazy[node * 2 + 2].s = max(lazy[node * 2 + 1].s, (ll)type);
        }
        return;
    }
    int mid = (l + r) / 2; //if current node range and update range overlap, recurse to both children
    updateRec(node * 2 + 1, l, mid, lq, rq, val, type);
    updateRec(node * 2 + 2, mid + 1, r, lq, rq, val, type);
    seg[node] = seg[node * 2 + 1] + seg[node * 2 + 2]; //use children to update current
}
void update(int lq, int rq, ll val, int n, int type) { updateRec(0, 0, n - 1, lq, rq, val, type); }
ll sumRec(int node, int l, int r, int lq, int rq)
{
    if(lazy[node].s) //if there is pending lazy update on this node
    {
        if(lazy[node].s == 1) seg[node] += lazy[node].f * (r - l + 1); //update the range by adding val the correct amt of times
        else seg[node] = lazy[node].f * (r - l + 1);
        if(l != r) //if not leaf node, store lazy updates for its children
        {
            if(lazy[node].s == 1) { lazy[node * 2 + 1].f += lazy[node].f; lazy[node * 2 + 2].f += lazy[node].f; }
            else { lazy[node * 2 + 1].f = lazy[node].f; lazy[node * 2 + 2].f = lazy[node].f; }
            lazy[node * 2 + 1].s = lazy[node * 2 + 2].s = max(lazy[node * 2 + 1].s, lazy[node].s);
        }
        lazy[node] = {0, 0};
    }
    if(l > rq || r < lq || l > r) return 0; //if update range not in current nodes range, return 0
    if(l >= lq && r <= rq) //if current node range completely inside of update range, add all from range to answer
        return seg[node];
    int mid = (l + r) / 2; //if current node range and update range overlap, recurse to both children and add them to answer
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
    int n, q, type, a, b, c;
    cin >> n >> q;
    for(int i = 0; i < n; i ++)
        cin >> nums[i];
    make(n);
    for(int i = 0; i < q; i ++)
    {
        cin >> type >> a >> b;
        if(type == 3)
            cout << sum(a-1, b-1, n) << "\n";
        else
        {
            cin >> c;
            update(a-1, b-1, c, n, type);
        }
    }
}
