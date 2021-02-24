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
    int n, ans = 0, cnt = 0, idx = 0;
    cin >> n;
    for(int i = 0; i < n; i ++)
    {
        cin >> endpts[i * 2].f; endpts[i * 2].s = 0;
        cin >> endpts[i * 2 + 1].f; endpts[i * 2 + 1].s = 1;
    }
    sort(endpts, endpts + n * 2);
    for(auto cur : endpts)
    {
        if(idx >= n * 2) break;
        if(cur.s == 0) cnt ++;
        else cnt --;
        ans = max(ans, cnt);
        idx ++;
    }
    cout << ans << "\n";
}
