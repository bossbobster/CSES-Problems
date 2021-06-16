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
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
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

struct chash
{
    const uint64_t C = ll(2e18*(3.14))+71; // large odd number
    const int RANDOM = rand(); // random 32-bit number
    ll operator()(ll x) const
    {
        // https://gcc.gnu.org/onlinedocs/gcc/Other-Builtins.html
        return __builtin_bswap64((x^RANDOM)*C);
    }
};

int nums[200010], pre[200010];
gp_hash_table<int, null_type, chash> in;
int main()
{
    input();
    int n, cur = 0, mx1 = 0, mx2 = 0;
    cin >> n;
    for(int i = 0; i < n; i ++)
        cin >> nums[i];
    pre[0] = 0;
    for(int i = 1; i <= n; i ++)
        pre[i] = pre[i-1] ^ nums[i-1];
    n++;
    for(int i = 30; i >= 0; i --)
    {
        in.clear();
        cur = cur | (1<<i);
        for(int i = 0; i < n; i ++)
            in.insert(cur & pre[i]);
        mx2 = mx1 | (1<<i);
        for(auto it : in)
            if(in.find(it ^ mx2) != in.end())
            {
                mx1 = mx2; break;
            }
    }
    cout << mx1 << "\n";
}
