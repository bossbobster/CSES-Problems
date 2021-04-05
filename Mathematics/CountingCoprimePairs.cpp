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
typedef pair<string, string> pss;
typedef pair<pii, int> piii;
typedef pair<string, int> psi;
typedef long long ll;
typedef pair<ll, ll> pll;
//#define max(n, m) ((n>m)?n:m)
//#define min(n, m) ((n<m)?n:m)
#define f first
#define s second

ll ans = 0, res;
int mod = 1000000007;
long long exp(long long base, long long power)
{
    if(power == 0) return 1;
    if(power == 1) return base;
    long long cur = exp(base, power / 2);
    long long ans = (cur * cur) % mod;
    if(power % 2 == 1) ans = (ans * base) % mod;
    return ans % mod;
}
int nums[100010];
vector<int> primes;
bool comp[1000010];
vector<int> fac[100010];
void findPrimes(int n)
{
    for(int i = 2; i <= n; i ++)
    {
        if(comp[i]) continue;
        primes.push_back(i);
        for(int j = 2; i*j <= n; j ++)
            comp[i*j] = true;
    }
}
int n, mx = 0;
int cnt[1000010];
vector<short> cur;
vector<int> curF;
void sub(int idx)
{
    if(idx == curF.size())
    {
        int num = 1;
        for(int i = 0; i < cur.size(); i ++)
            if(cur[i])
                num *= curF[i];
        cnt[num] ++;
        return;
    }
    cur.push_back(0);
    sub(idx + 1);
    cur.pop_back(); cur.push_back(1);
    sub(idx + 1);
    cur.pop_back();
}
void sub2(int idx)
{
    if(idx == curF.size())
    {
        int num = 1, cntcnt = 0;
        for(int i = 0; i < cur.size(); i ++)
            if(cur[i])
            {
                num *= curF[i];
                cntcnt ++;
            }
        if(cntcnt == 0) return;
        if(cntcnt % 2 == 1) res += cnt[num];
        else res -= cnt[num];
        return;
    }
    cur.push_back(0);
    sub2(idx + 1);
    cur.pop_back(); cur.push_back(1);
    sub2(idx + 1);
    cur.pop_back();
}
int main()
{
    cin >> n;
    for(int i = 0; i < n; i ++)
    {
        cin >> nums[i];
        mx = max(mx, nums[i]);
    }
    findPrimes(mx + 5);
    for(int i = 0; i < n; i ++)
    {
        res = nums[i];
        for(int j = 0; primes[j] <= sqrt(nums[i]); j ++)
        {
            if(nums[i] % primes[j] == 0)
            {
                fac[i].push_back(primes[j]);
                while(res % primes[j] == 0) res /= primes[j];
            }
        }
        if(res != 1) fac[i].push_back(res);
    }
    for(int i = 0; i < n; i ++)
    {
        curF.clear(); curF = fac[i];
        sub(0);
    }
    for(int i = 0; i < n; i ++)
    {
        res = 0;
        curF.clear(); curF = fac[i];
        sub2(0);
        if(res == 0) res ++;
        ans += n-res;
    }
    cout << ans/2 << "\n";
}
