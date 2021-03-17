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
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
using namespace std;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef long long ll;
typedef pair<ll, ll> pll;
//#define max(n, m) ((n>m)?n:m)
//#define min(n, m) ((n<m)?n:m)
#define f first
#define s second

ll nums[21];
bool used[21];
ll n, k, mult; unsigned long long ans = 0;
void PIE(int n1, int idx, int m)
{
    if(n1 == 0)
    {
        mult = 1;
        for(int i = 0; i < k; i ++)
            if(used[i])
            {
                if(n / mult < nums[i]) return;
                mult *= nums[i];
            }
        if(m % 2 == 1) ans += n/mult;
        else ans -= n/mult;
        return;
    }
    for(int i = (int)m - n1 + idx; i < k - n1 + 1; i ++)
    {
        if(used[i]) continue;
        used[i] = true;
        PIE(n1 - 1, idx, m);
        idx ++;
        used[i] = false;
    }
}

int main()
{
    cin >> n >> k;
    for(int i = 0; i < k; i ++)
        cin >> nums[i];
    for(int i = 1; i <= k; i ++)
        PIE((int)i, 0, i);
    cout << ans << "\n";
}
