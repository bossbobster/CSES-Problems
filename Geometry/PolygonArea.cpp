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

pll nums[1010];
int main()
{
    int n;
    cin >> n;
    ll ans = 0;
    for(int i = 0; i < n; i ++)
        cin >> nums[i].f >> nums[i].s;
    for(int i = 0; i < n; i ++)
        ans += (nums[i].f * nums[(i + 1) % n].s);
    for(int i = 0; i < n; i ++)
        ans -= (nums[(i + 1) % n].f * nums[i].s);
    cout << abs(ans) << "\n";
}
