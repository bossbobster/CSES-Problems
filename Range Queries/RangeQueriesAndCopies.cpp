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

int n, q, type, k, a, b;
struct node
{
    int l, r, copy;
    node* left = nullptr;
    node* right = nullptr;
    ll val;
    node(){}
    node(node* cop) { l = cop->l; r = cop->r; copy = cop->copy; left = cop->left; right = cop->right; val = cop->val; }
};
vector<node*> copies;
int nums[200010];
node* update(node* cur, int idx, int val, int copy)
{
    if(cur->l != 0 || cur->r != n-1)
        cur = new node(cur);
    cur->copy = copy;
    if(cur->left == nullptr && cur->right == nullptr)
    {
        cur->val = val;
        return cur;
    }
    int mid = (cur->l+cur->r)/2;
    if(idx >= cur->l && idx <= mid)
        cur->left = update(cur->left, idx, val, copy);
    else
        cur->right = update(cur->right, idx, val, copy);
    cur->val = cur->left->val + cur->right->val;
    return cur;
}
ll sum(node* cur, int lq, int rq)
{
    if(cur->r < lq || cur->l > rq)
        return 0;
    if(lq <= cur->l && rq >= cur->r)
        return cur->val;
    return sum(cur->left, lq, rq) + sum(cur->right, lq, rq);
}
ll make(node* cur, int l, int r)
{
    cur->l = l; cur->r = r; cur->copy = 0;
    if(l == r)
        return cur->val = nums[l];
    int mid = (l+r)/2;
    cur->left = new node(); cur->right = new node();
    return cur->val = make(cur->left, l, mid) + make(cur->right, mid+1, r);
}
int main()
{
    input();
    cin >> n >> q;
    for(int i = 0; i < n; i ++)
        cin >> nums[i];
    node* root = new node();
    make(root, 0, n-1);
    copies.push_back(root);
    while(q--)
    {
        cin >> type >> k; k--;
        if(type == 1)
        {
            cin >> a >> b; a--;
            update(copies[k], a, b, k);
        }
        else if(type == 2)
        {
            cin >> a >> b; a--; b--;
            cout << sum(copies[k], a, b) << "\n";
        }
        else
        {
            node* tmp = new node(copies[k]);
            tmp->copy = (int)copies.size();
            copies.push_back(tmp);
        }
    }
}
