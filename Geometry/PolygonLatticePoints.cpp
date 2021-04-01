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

long long gcd(long long l1, long long l2)
{
    if(l1 < l2) swap(l1, l2);
    if(l2 == 0) return l1;
    return gcd(l2, l1 % l2);
}
pll nums[1010];
int main()
{
    int n;
    cin >> n;
    ll area = 0, in = 0, bound = 0; // in + bound/2 - 1 = area (Pick's Theorem)
    for(int i = 0; i < n; i ++)
        cin >> nums[i].f >> nums[i].s;
    for(int i = 0; i < n; i ++)
        area += (nums[i].f * nums[(i + 1) % n].s);
    for(int i = 0; i < n; i ++)
        area -= (nums[(i + 1) % n].f * nums[i].s);
    area /= 2;
    area = abs(area);
    for(int i = 0; i < n; i ++)
        bound += gcd(abs(nums[i].f - nums[(i + 1) % n].f), abs(nums[i].s - nums[(i + 1) % n].s));
    in = area + 1 - bound/2;
    cout << in << " " << bound << "\n";
}
