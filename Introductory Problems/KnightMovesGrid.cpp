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
#include <utility>
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
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("bmi,bmi2,popcnt,lzcnt")
#pragma GCC target("avx2") // remember to remove if runtime error
//#pragma GCC ivdep // only add this if nothing else works (since it might break stuff)

/*

     ._________.
     |_________|
   ---------------
  |_____• U •_____|
 -------------------
|___________________|

 */

bitset<1010> vis[1010];
int dist[1010][1010];
queue<pii> q;
int dc[8] = {1, 2, 2, 1, -1, -2, -2, -1}, dr[8] = {-2, -1, 1, 2, 2, 1, -1, -2};

int main()
{
    input();
    int n;
    cin >> n;
    q.push({0, 0});
    vis[0][0] = 1; dist[0][0] = 0;
    while(!q.empty())
    {
        pii p = q.front();
        q.pop();
        for(int i = 0; i < 8; i ++)
        {
            int nr = p.f+dr[i], nc = p.s+dc[i];
            if(nr >= 0 && nr < n && nc >= 0 && nc < n && !vis[nr][nc])
            {
                dist[nr][nc] = dist[p.f][p.s]+1;
                vis[nr][nc] = 1;
                q.push({nr, nc});
            }
        }
    }
    for(int i = 0; i < n; i ++)
        for(int j = 0; j < n; j ++)
            cout << dist[i][j] << ((j==n-1)?'\n':' ');
}
