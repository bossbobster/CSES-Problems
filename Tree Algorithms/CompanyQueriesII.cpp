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

int n, q;
int idx[200010];
int arr[400010], dep[400010];
vector<int> adj[200010];
int cnt = 0;
void euler(int cur, int par, int d)
{
    dep[cnt] = d;
    arr[cnt] = cur;
    idx[cur] = cnt++;
    for(auto it : adj[cur])
        if(it != par)
        {
            euler(it, cur, d+1);
            dep[cnt] = d;
            arr[cnt++] = cur;
        }
}
pii pre[400010][25];
void sparse(int n)
{
    for(int i = 0; i < n; i ++)
        pre[i][0] = {dep[i], i};
    for(int i = 1; i <= floor(log2(n)); i ++)
        for(int j = 0; j <= n - (1 << i); j ++)
            pre[j][i] = min(pre[j][i - 1], pre[j + (1 << (i - 1))][i - 1]);
    
}
int minQ(int l, int r)
{
    int log = floor(log2(r - l + 1));
    if(pre[l][log].f < pre[r-(1<<log)+1][log].f) return arr[pre[l][log].s];
    return arr[pre[r-(1<<log)+1][log].s];
}
int main()
{
    input();
    int num, a, b;
    cin >> n >> q;
    for(int i = 1; i < n; i ++)
    {
        cin >> num; num--;
        adj[num].push_back(i);
    }
    euler(0, -1, 0);
    sparse(2*n);
    while(q--)
    {
        cin >> a >> b; a--; b--;
        cout << minQ(min(idx[a], idx[b]), max(idx[a], idx[b]))+1 << "\n";
    }
}
