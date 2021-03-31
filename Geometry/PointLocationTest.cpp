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

struct pt
{
    ll x, y;
};
ll cp(pt p1, pt p2)
{
    return p1.x * p2.y - p1.y * p2.x;
}
string ccw(pt p1, pt p2, pt p3)
{
    pt p4 = {p2.x - p1.x, p2.y - p1.y};
    pt p5 = {p3.x - p1.x, p3.y - p1.y};
    if(cp(p4, p5) > 0) return "LEFT"; // ccw
    if(cp(p4, p5) == 0) return "TOUCH";
    return "RIGHT"; // cw
}
int main()
{
    ll t, a, b, c, d, e, e2;
    cin >> t;
    for(int i = 0; i < t; i ++)
    {
        cin >> a >> b >> c >> d >> e >> e2;
        cout << ccw({a, b}, {c, d}, {e, e2}) << "\n";
    }
}
