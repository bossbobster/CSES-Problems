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
//#define cin fin
//#define cout fout

int nums[3][3];
bitset<362890> vis;
queue<pair<vector<int>, int>> q;
const int fac[9] = {0, 1, 2, 6, 24, 120, 720, 5040, 40320};
int main()
{
    input();
    for(int i = 0; i < 3; i ++)
        for(int j = 0; j < 3; j ++)
            cin >> nums[i][j], nums[i][j]--;
    q.push({{nums[0][0], nums[0][1], nums[0][2], nums[1][0], nums[1][1], nums[1][2], nums[2][0], nums[2][1], nums[2][2]}, 0});
    while(!q.empty())
    {
        vector<int> cur = q.front().f; int d = q.front().s;
        q.pop();
        int num = 0;
        for(int i = 0; i < 9; i ++)
            num += fac[i]*cur[i];
        if(num == 362879)
        {
            cout << d << '\n';
            return 0;
        }
        if(vis[num]) continue;
        vis[num] = 1;
        swap(cur[0], cur[1]); q.push({cur, d+1}); swap(cur[0], cur[1]);
        swap(cur[1], cur[2]); q.push({cur, d+1}); swap(cur[1], cur[2]);
        swap(cur[3], cur[4]); q.push({cur, d+1}); swap(cur[3], cur[4]);
        swap(cur[4], cur[5]); q.push({cur, d+1}); swap(cur[4], cur[5]);
        swap(cur[6], cur[7]); q.push({cur, d+1}); swap(cur[6], cur[7]);
        swap(cur[7], cur[8]); q.push({cur, d+1}); swap(cur[7], cur[8]);
        
        swap(cur[0], cur[3]); q.push({cur, d+1}); swap(cur[0], cur[3]);
        swap(cur[1], cur[4]); q.push({cur, d+1}); swap(cur[1], cur[4]);
        swap(cur[2], cur[5]); q.push({cur, d+1}); swap(cur[2], cur[5]);
        swap(cur[3], cur[6]); q.push({cur, d+1}); swap(cur[3], cur[6]);
        swap(cur[4], cur[7]); q.push({cur, d+1}); swap(cur[4], cur[7]);
        swap(cur[5], cur[8]); q.push({cur, d+1}); swap(cur[5], cur[8]);
    }
}
