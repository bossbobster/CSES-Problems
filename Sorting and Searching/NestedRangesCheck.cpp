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
#include <bitset>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <complex>
#include <valarray>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef pair<int, int> pii;
typedef pair<int, string> pis;
typedef pair<string, string> pss;
typedef pair<int, char> pic;
typedef pair<pii, int> piii;
typedef pair<double, double> pdd;
typedef pair<float, float> pff;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<ll, ll> pll;
typedef pair<int, ll> pil;
typedef pair<ull, ull> pull;
typedef complex<double> cd;
//#define max(n, m) ((n>m)?n:m)
//#define min(n, m) ((n<m)?n:m)
#define f first
#define s second
#define input() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

struct chash
{
    const uint64_t C = ll(2e18*(3.14))+71;
    const int RANDOM = rand();
    ll operator()(ll x) const
    {
        return __builtin_bswap64((x^RANDOM)*C);
    }
};

int sum(int arr[], int idx)
{
    int ans = 0;
    idx ++;
    while(idx > 0)
    {
        ans += arr[idx];
        idx -= idx & (-idx);
    }
    return ans;
}
void update(int arr[], int idx, int val, int size)
{
    idx ++;
    while(idx <= size)
    {
        arr[idx] += val;
        idx += idx & (-idx);
    }
}
struct st
{
    int a, b, idx;
};
bool comp1(st s1, st s2)
{
    if(s1.b == s2.b) return s1.a > s2.a;
    return s1.b < s2.b;
}
bool comp2(st s1, st s2)
{
    if(s1.a == s2.a) return s1.b > s2.b;
    return s1.a < s2.a;
}
gp_hash_table<int, int, chash> hsh;
set<int> coords;
st nums[200010];
int bit[400010];
int bit2[400010];
int ans1[200010];
int ans2[200010];
int main()
{
    input();
    int n, indx = 0;
    cin >> n;
    for(int i = 0; i < n; i ++)
    {
        cin >> nums[i].a >> nums[i].b;
        coords.insert(nums[i].a); coords.insert(nums[i].b);
        nums[i].idx = i;
    }
    sort(nums, nums + n, comp1);
    for(auto cur : coords)
    {
        hsh[cur] = indx;
        indx ++;
    }
    for(int i = 0; i < n; i ++)
    {
        ans1[nums[i].idx] = sum(bit, hsh[nums[i].b]) - sum(bit, hsh[nums[i].a] - 1);
        update(bit, hsh[nums[i].a], 1, (int)coords.size());
    }
    sort(nums, nums + n, comp2);
    for(int i = 0; i < n; i ++)
    {
        ans2[nums[i].idx] = sum(bit2, (int)coords.size() - 1) - sum(bit2, hsh[nums[i].b] - 1);
        update(bit2, hsh[nums[i].b], 1, (int)coords.size());
    }
    for(int i = 0; i < n; i ++)
        cout << min(1, ans1[i]) << " ";
    cout << "\n";
    for(int i = 0; i < n; i ++)
        cout << min(1, ans2[i]) << " ";
    cout << "\n";
    return 0;
}
