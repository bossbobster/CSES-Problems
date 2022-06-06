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
#include <bitset>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <complex>
#include <valarray>
using namespace std;
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
typedef pair<int, int> pii;
typedef pair<int, string> pis;
typedef pair<int, short> pish;
typedef pair<string, string> pss;
typedef pair<int, char> pic;
typedef pair<pii, int> piii;
typedef pair<double, double> pdd;
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
typedef pair<int, ll> pil;
typedef pair<ull, ull> pull;
typedef pair<ld, ld> pld;
typedef complex<double> cd;
//#define max(n, m) ((n>m)?n:m)
//#define min(n, m) ((n<m)?n:m)
#define f first
#define s second
#define input() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define eps 1e-9
#define leni(x) sizeof(x)/sizeof(int)
//#define cin fin
//#define cout fout

struct node
{
    ll val, tot = 0;
    int p, sz;
    node *l, *r;
    bool rev = false;
    node(ll v) { val = v; p = rand(); sz = 1; l = nullptr; r = nullptr; }
    node(ll v, node *le, node *ri) { val = v; p = rand(); sz = 1; l = le; r = ri; }
};

int siz(node* nd)
{
    if(!nd) return 0;
    return nd->sz;
}

void split(node* root, node*& l, node *& r, int v)
{
    if(!root)
    {
        l = r = nullptr;
        return;
    }
    if(root->rev)
    {
        swap(root->l, root->r);
        root->rev = false;
        if(root->l) root->l->rev = !root->l->rev;
        if(root->r) root->r->rev = !root->r->rev;
    }
    if(siz(root->l) < v)
    {
        split(root->r, root->r, r, v-siz(root->l)-1);
        l = root;
    }
    else
    {
        split(root->l, l, root->l, v);
        r = root;
    }
    root->sz = siz(root->l)+siz(root->r)+1;
    root->tot = ((root->l)?root->l->tot:0) + ((root->r)?root->r->tot:0) + root->val;
}

void merge(node*& root, node* l, node* r)
{
    if(!l || !r)
    {
        root = l?l:r;
        return;
    }
    if(l->rev)
    {
        swap(l->l, l->r);
        l->rev = false;
        if(l->l) l->l->rev = !l->l->rev;
        if(l->r) l->r->rev = !l->r->rev;
    }
    if(r->rev)
    {
        swap(r->l, r->r);
        r->rev = false;
        if(r->l) r->l->rev = !r->l->rev;
        if(r->r) r->r->rev = !r->r->rev;
    }
    if(l->p < r->p)
    {
        merge(l->r, l->r, r);
        root = l;
    }
    else
    {
        merge(r->l, l, r->l);
        root = r;
    }
    root->sz = siz(root->l)+siz(root->r)+1;
    root->tot = ((root->l)?root->l->tot:0) + ((root->r)?root->r->tot:0) + root->val;
}
void build(node* root)
{
    if(!root) return;
    build(root->l); build(root->r);
    root->tot = ((root->l)?root->l->tot:0) + ((root->r)?root->r->tot:0) + root->val;
}
ll nums[200010];
int main()
{
    input();
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i ++)
        cin >> nums[i];
    node* root = new node(nums[0]);
    for(int i = 1; i < n; i ++)
        merge(root, root, new node(nums[i]));
    build(root);
    int type, a, b;
    while(m--)
    {
        cin >> type >> a >> b; a--; b--;
        if(type == 1)
        {
            node *l, *r, *l2, *r2;
            split(root, l, r, a);
            split(r, l2, r2, b-a+1);
            l2->rev = !l2->rev;
            merge(root, l, l2);
            merge(root, root, r2);
        }
        else
        {
            node *l, *r, *l2, *r2;
            split(root, l, r, a);
            split(r, l2, r2, b-a+1);
            cout << l2->tot << '\n';
            merge(root, l, l2);
            merge(root, root, r2);
        }
    }
}
