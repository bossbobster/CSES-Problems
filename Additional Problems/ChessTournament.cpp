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
#include <array>
#include <bitset>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <complex>
#include <valarray>
#include <memory>
#include <cassert>
#include <chrono>
#include <type_traits>
#include <stdexcept>
#include <regex>
#include <numeric>
using namespace std;
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
typedef pair<int, int> pii;
typedef pair<int, string> pis;
typedef pair<pis, string> piss;
typedef pair<int, short> pish;
typedef pair<string, string> pss;
typedef pair<int, char> pic;
typedef pair<pii, int> piii;
typedef pair<double, double> pdd;
typedef pair<double, int> pdi;
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
typedef pair<ld, int> pldi;
typedef pair<int, ll> pil;
typedef pair<ll, int> pli;
typedef pair<ull, ull> pull;
typedef pair<ld, ld> pld;
typedef complex<double> cd;
//#define max(n, m) ((n>m)?n:m)
//#define min(n, m) ((n<m)?n:m)
#define f first
#define s second
#define input() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
//#define eps 1e-8
//#define eps2 1e-15
#define leni(x) sizeof(x)/sizeof(int)
#define v(i,j,k) for(i=j;i<k;i++)
#define pi 3.14159265358979323846
//#define cin fin
//#define cout fout
//#define fin cin
//#define fout cout
#pragma GCC optimize("O1,O2,O3,Ofast,unroll-loops")

/*

     ._________.
     |_________|
   ---------------
  |_____• U •_____|
 -------------------
|___________________|


 */

set<pii, greater<pii>> all;
int main()
{
    input();
    int n, num;
    cin >> n;
    for(int i = 0; i < n; i ++)
    {
        cin >> num;
        if(num)
            all.insert({num, i});
    }
    vector<pii> ans;
    bool bad = false;
    while(!all.empty())
    {
        pii p = *all.begin();
        if(p.f == 0) break;
        int cnt = p.f;
        vector<pii> in;
        for(auto it = next(all.begin()); it != all.end(); ++it)
        {
            if(p.f == 0) break;
            p.f--;
            ans.push_back({p.s+1, it->s+1});
            in.push_back({it->f-1, it->s});
        }
        if(p.f != 0) { bad = true; break; }
        for(int i = 0; i < cnt; i ++)
            all.erase(next(all.begin()));
        all.erase(all.begin());
        for(auto it : in)
            if(it.f != 0)
                all.insert(it);
    }
    if(bad) cout << "IMPOSSIBLE\n";
    else
    {
        cout << ans.size() << '\n';
        for(auto it : ans)
            cout << it.f << ' ' << it.s << '\n';
    }
}
