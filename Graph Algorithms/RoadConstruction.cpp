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
//using namespace __gnu_pbds;
using namespace std;
typedef pair<int, int> pii;
typedef pair<int, string> pis;
typedef pair<int, char> pic;
typedef pair<pii, int> piii;
typedef long long ll;
typedef pair<ll, ll> pll;
//#define max(n, m) ((n>m)?n:m)
//#define min(n, m) ((n<m)?n:m)
#define f first
#define s second

int mx = 0;
struct dsu
{
    // parent array
    int par[100010];
    // size array
    int size[100010];
    // constructor
    dsu(int s)
    {
        for(int i = 0; i <= s; i ++)
        {
            par[i] = i; size[i] = 1;
        }
    }
    // find root of n
    int root(int n)
    {
        if(par[n] == n || par[n] == -1)
            return n;
        return par[n] = root(par[n]);
    }
    // return true if n and m are in the same CC
    bool con(int n, int m)
    {
        return (root(n) == root(m));
    }
    // connect n and m
    void un(int n, int m)
    {
        n = root(n); m = root(m);
        if(n == m) return;
        if(size[n] < size[m])
            swap(n, m);
        par[m] = n;
        size[n] += size[m];
        mx = max(mx, size[n]);
    }
};

int main()
{
    int n, m, a, b, num;
    cin >> n >> m;
    num = n;
    dsu d = dsu(n);
    for(int i = 0; i < m; i ++)
    {
        cin >> a >> b; a--; b--;
        if(!d.con(a, b)) num --;
        d.un(a, b);
        cout << num << " " << mx << "\n";
    }
}
