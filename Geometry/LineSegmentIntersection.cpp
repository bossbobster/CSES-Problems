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
typedef pair<ll, ll> pll;
//#define max(n, m) ((n>m)?n:m)
//#define min(n, m) ((n<m)?n:m)
#define f first
#define s second

int c[4];
struct pt
{
    ll x, y;
    const bool operator<=(const pt& other) const
    {
        if(x == other.x) return y <= other.y;
        return x <= other.x;
    }
    const bool operator>=(const pt& other) const
    {
        if(x == other.x) return y >= other.y;
        return x >= other.x;
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
    if(cp(p4, p5) == 0) return 0;
    return -1; // cw
}
string inter(pt p1, pt p2, pt p3, pt p4)
{
    c[0] = ccw(p1, p2, p3); c[1] = ccw(p1, p2, p4); c[2] = ccw(p3, p4, p1); c[3] = ccw(p3, p4, p2);
    if(c[0] != c[1] && c[2] != c[3]) return "YES";
    if(ccw(p1, p2, p3) == 0) //case where segments are both on the same line
        if((!c[0] && p1 <= p3 && p3 <= p2) || (!c[0] && p1 >= p3 && p3 >= p2) || (!c[1] && p1 <= p4 && p4 <= p2) || (!c[1] && p1 >= p4 && p4 >= p2)  || (!c[2] && p3 <= p1 && p1 <= p4) || (!c[2] && p3 >= p1 && p1 >= p4) || (!c[3] && p3 <= p2 && p2 <= p4) || (!c[3] && p3 >= p2 && p2 >= p4))
            return "YES";
    return "NO";
}
int main()
{
    ll t, x1, x2, x3, x4, y1, y2, y3, y4;
    cin >> t;
    for(int i = 0; i < t; i ++)
    {
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
        cout << inter({x1, y1}, {x2, y2}, {x3, y3}, {x4, y4}) << "\n";
    }
}
