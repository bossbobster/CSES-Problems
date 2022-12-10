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
//#define cin fin
//#define cout fout
#pragma GCC optimize("O1,O2,O3,Ofast,unroll-loops")

int nums[200010], deg[200010];
set<int> lef;
int main()
{
    input();
    int n;
    cin >> n;
    for(int i = 0; i < n-2; i ++)
        cin >> nums[i], nums[i]--;
    for(int i = 0; i < n; i ++)
        deg[i] = 1;
    for(int i = 0; i < n-2; i ++)
        deg[nums[i]] ++;
    for(int i = 0; i < n; i ++)
        if(deg[i] == 1)
            lef.insert(i);
    for(int i = 0; i < n-2; i ++)
    {
        int con = *lef.begin();
        cout << nums[i]+1 << ' ' << con+1 << '\n';
        deg[con]--; deg[nums[i]]--;
        lef.erase(con);
        if(deg[nums[i]] == 1) lef.insert(nums[i]);
    }
    int pre = -1;
    for(int i = 0; i < n; i ++)
        if(deg[i] == 1)
        {
            if(pre == -1) pre = i;
            else
            {
                cout << pre+1 << ' ' << i+1 << '\n';
                return 0;
            }
        }
    return 0;
}
