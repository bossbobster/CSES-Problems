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
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef pair<int, int> pii;
typedef pair<int, string> pis;
typedef pair<int, char> pic;
typedef pair<pii, int> piii;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
//#define max(n, m) ((n>m)?n:m)
//#define min(n, m) ((n<m)?n:m)
#define f first
#define s second

struct chash { // use most bits rather than just the lowest ones
    const uint64_t C = ll(2e18*(3.14))+71; // large odd number
    const int RANDOM = rand(); // random 32-bit number
    ll operator()(ll x) const {
        // https://gcc.gnu.org/onlinedocs/gcc/Other-Builtins.html
        return __builtin_bswap64((x^RANDOM)*C);
    }
};
ll nums[50];
gp_hash_table<ll, int, chash> m;
int main()
{
    int n;
    ll x, sum, ans = 0;
    cin >> n >> x;
    for(int i = 0; i < n; i ++)
        cin >> nums[i];
    for(int i = 0; i < (1 << n/2); i ++)
    {
        sum = 0;
        for(int j = 0; j < n/2; j ++)
            if(i & (1 << j))
                sum += nums[j];
        m[sum] ++;
    }
    for(int i = 0; i < (1 << (n-n/2)); i ++)
    {
        sum = 0;
        for(int j = n/2; j < n; j ++)
            if(i & (1 << j - n/2))
                sum += nums[j];
        ans += m[x - sum];
    }
    cout << ans << "\n";
}
