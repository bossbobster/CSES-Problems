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
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
using namespace std;
typedef pair<int, int> pii;
typedef pair<int, string> pis;
typedef pair<string, string> pss;
typedef pair<int, char> pic;
typedef pair<pii, int> piii;
typedef pair<double, double> pdd;
typedef pair<float, float> pff;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<ll, ll> pll;
typedef pair<int, ll> pil;
typedef pair<ull, ull> pull;
typedef pair<ld, ld> pld;
typedef complex<double> cd;
//#define max(n, m) ((n>m)?n:m)
//#define min(n, m) ((n<m)?n:m)
#define f first
#define s second
#define input() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 
int n, sz = 2000010;
piii ver[200010], hor[100010];
ll bit[2000010];
void update(int idx, int val)
{
    idx ++;
    while(idx <= sz)
    {
        bit[idx] += val;
        idx += idx & (-idx);
    }
}
ll sum(int idx)
{
    ll ans = 0;
    idx ++;
    while(idx > 0)
    {
        ans += bit[idx];
        idx -= idx & (-idx);
    }
    return ans;
}
int main()
{
    input();
    int idx = 0, idx2 = 0, idx3 = 0, x1, x2, y1, y2;
    ll ans = 0;
    cin >> n;
    for(int i = 0; i < n; i ++)
    {
        cin >> x1 >> y1 >> x2 >> y2; x1 += 1000000, y1 += 1000000, x2 += 1000000, y2 += 1000000;
        if(x1 == x2)
            ver[idx++] = {{y1, x1}, 1}, ver[idx++] = {{y2, x1}, -1};
        else
            hor[idx2++] = {{y1, x1}, x2};
    }
    sort(hor, hor+idx2); sort(ver, ver+idx);
    for(int i = 0; i < idx; i ++)
    {
        while(idx3 < idx2 && hor[idx3].f.f < ver[i].f.f)
            ans += sum(hor[idx3].s) - sum(hor[idx3++].f.s-1);
        update(ver[i].f.s, ver[i].s);
    }
    cout << ans << '\n';
}
