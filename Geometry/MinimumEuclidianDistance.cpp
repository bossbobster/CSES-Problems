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

struct pt
{
    ll x, y;
};
struct comp
{
    const bool operator()(pt p1, pt p2)
    {
        if(p1.y == p2.y) return p1.x < p2.x;
        return p1.y < p2.y;
    }
};
bool comp2(pt p1, pt p2)
{
    if(p1.x == p2.x) return p1.y < p2.y;
    return p1.x < p2.x;
}
ll len(pt p1, pt p2)
{
    return abs(p1.x - p2.x) * abs(p1.x - p2.x) + abs(p1.y - p2.y) * abs(p1.y - p2.y);
}
pt nums[200010];
set<pt, comp> cur;
int main()
{
    int n, idx = 0;
    ll ans = 8000000000000000000, dist;
    cin >> n;
    for(int i = 0; i < n; i ++)
        cin >> nums[i].x >> nums[i].y;
    sort(nums, nums + n, comp2);
    cur.insert(nums[0]);
    for(int i = 1; i < n; i ++)
    {
        dist = sqrt(ans) + 1;
        while(nums[i].x - nums[idx].x > dist) { cur.erase(nums[idx]); idx ++; }
        if(!cur.empty())
            for(auto it = cur.lower_bound({nums[i].x, nums[i].y - dist}); it != cur.upper_bound({nums[i].x, nums[i].y + dist}); ++it)
                ans = min(ans, len(*it, nums[i]));
        cur.insert(nums[i]);
    }
    cout << ans << "\n";
}
