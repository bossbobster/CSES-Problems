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
    bool operator<(const pt& p1) const
    {
        if(p1.x == x) return y < p1.y;
        return x < p1.x;
    }
};

ll cp(pt p1, pt p2)
{
    return p1.x * p2.y - p1.y * p2.x;
}

int ccw(pt p1, pt p2, pt p3)
{
    pt p4 = {p2.x - p1.x, p2.y - p1.y};
    pt p5 = {p3.x - p1.x, p3.y - p1.y};
    if(cp(p4, p5) > 0) return 1; // ccw
    return -1; // cw
}

set<pt> points;
pt nums[200010];
vector<pt> upper;
vector<pt> lower;
int main()
{
    int n, ans = 0;
    cin >> n;
    for(int i = 0; i < n; i ++)
        cin >> nums[i].x >> nums[i].y;
    sort(nums, nums + n);
    for(int i = 0; i < n; i ++)
    {
        while(upper.size() >= 2 && ccw(upper[upper.size() - 2], upper[upper.size() - 1], nums[i]) == 1)
            upper.pop_back();
        upper.push_back(nums[i]);
    }
    for(int i = n - 1; i >= 0; i --)
    {
        while(lower.size() >= 2 && ccw(lower[lower.size() - 2], lower[lower.size() - 1], nums[i]) == 1)
            lower.pop_back();
        lower.push_back(nums[i]);
    }
    ans = (int)(lower.size() + upper.size() - 2);
    cout << ans << "\n";
    for(int i = 0; i < lower.size(); i ++)
        cout << lower[i].x << " " << lower[i].y << "\n";
    for(int i = 1; i < upper.size() - 1; i ++)
        cout << upper[i].x << " " << upper[i].y << "\n";
}
