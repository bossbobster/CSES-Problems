#include <iostream>
#include <string.h>
#include <fstream>
#include <stdio.h>
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
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
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

int nums[200010];
gp_hash_table<int, int, chash> m;
int main()
{
    int n, target;
    cin >> n >> target;
    for(int i = 0; i < n; i ++)
        cin >> nums[i];
    for(int i = 0; i < n; i ++)
    {
        if(m.find(target - nums[i]) != m.end())
        {
            cout << m[target - nums[i]]+1 << " " << i+1 << "\n";
            return 0;
        }
        m[nums[i]] = i;
    }
    cout << "IMPOSSIBLE\n";
}
