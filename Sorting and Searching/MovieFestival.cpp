#include <iostream>
#include <iomanip>
#include <algorithm>
#include <math.h>
#include <vector>
#include <queue>
#include <bitset>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
using namespace std;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef long long ll;
typedef pair<ll, ll> pll;
#define max(n, m) ((n>m)?n:m)
#define min(n, m) ((n<m)?n:m)
#define f first
#define s second
 
pii endpts[400010];
int main()
{
    int n, ans = 0, pr = 0;
    cin >> n;
    for(int i = 0; i < n; i ++)
        cin >> endpts[i].s >> endpts[i].f;
    sort(endpts, endpts + n);
    for(int i = 0; i < n; i ++)
    {
        if(pr <= endpts[i].s)
        {
            ans ++;
            pr = endpts[i].f;
        }
    }
    cout << ans << "\n";
}
