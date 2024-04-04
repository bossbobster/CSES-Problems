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

int cnt[26];
int main()
{
    input();
    int n, rem;
    string st;
    cin >> st;
    n = st.length();
    for(auto it : st)
        cnt[it-'A']++;
    string ans = "";
    ans.reserve(n);
    for(int i = 0; i < n; i ++)
    {
        rem = n-i;
        bool done = false;
        for(int j = 0; j < 26; j ++)
        {
            if(ans.size() && j == ans.back()-'A') continue;
            if(rem%2 == 1 && cnt[j] > rem/2+1)
            {
                cout << "-1\n";
                return 0;
            }
            else if(rem%2 == 1 && cnt[j] > rem/2)
            {
                ans += ('A'+j);
                cnt[j]--;
                done = true;
                break;
            }
        }
        if(!done)
            for(int j = 0; j < 26; j ++)
            {
                if(ans.size() && j == ans.back()-'A') continue;
                if(cnt[j])
                {
                    ans += ('A'+j);
                    cnt[j]--;
                    break;
                }
            }
    }
    if(ans.size() != n) cout << "-1\n";
    else cout << ans << '\n';
}
