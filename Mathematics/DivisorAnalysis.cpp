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

ll n, num = 1, num1 = 1, num2 = 1, sum = 1, mod = 1000000007;
pll nums[100010];
ll exp(ll base, ll power)
{
    if(power == 0) return 1;
    if(power == 1) return base;
    ll cur = exp(base, power / 2);
    ll ans = (cur * cur) % mod;
    if(power % 2 == 1) ans = (ans * base) % mod;
    return ans % mod;
}
ll findSum(ll mult, ll cur)
{
    if(cur == 0) return 1;
    if(cur == 1) return (mult + 1) % mod;
    if(cur % 2 == 1)
        return ((mult + 1) * findSum((mult * mult) % mod, (cur-1) / 2)) % mod;
    return (1 + ((mult * (mult + 1) % mod) * findSum((mult * mult) % mod, (cur/2) - 1))) % mod;
}
int main()
{
    cin >> n;
    bool sq = true;
    for(int i = 0; i < n; i ++)
        cin >> nums[i].f >> nums[i].s;
    for(int i = 0; i < n; i ++)
    {
        if(nums[i].s % 2 == 1) sq = false;
        num1 = (num1 * (nums[i].s + 1)) % mod;
        num2 = (num2 * (nums[i].s + 1)) % (mod - 1);
        num = (num * exp(nums[i].f, nums[i].s)) % mod;
    }
    ll tmp = exp(num, num2);
    ll mult = exp(tmp, (mod + 1)/4);
    if(sq) mult = mod - mult;
    for(int i = 0; i < n; i ++)
    {
        tmp = findSum(nums[i].f, nums[i].s) % mod;
        sum = (sum * tmp) % mod;
    }
    cout << num1 << " " << sum << " " << mult << "\n";
}
