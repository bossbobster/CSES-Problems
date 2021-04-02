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

ll nums[200010];
int main()
{
    int n, cnt = 0, cur;
    ll ans = 0;
    cin >> n;
    for(int i = 0; i < n; i ++)
        cin >> nums[i];
    ans ^= nums[0];
    for(int i = 1; i < n; i ++)
    {
        cur = (n - i);
        while(cur % 2 == 0) { cnt ++; cur /= 2; }
        cur = i;
        while(cur % 2 == 0) { cnt --; cur /= 2; }
        if(!cnt) ans ^= nums[i];
    }
    cout << ans << "\n";
}
