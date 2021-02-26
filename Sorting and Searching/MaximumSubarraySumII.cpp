#include <iostream>
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
using namespace std;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef long long ll;
typedef pair<ll, ll> pll;
#define max(n, m) ((n>m)?n:m)
#define min(n, m) ((n<m)?n:m)
#define f first
#define s second

ll nums[200010];
ll pre[200010];
multiset<ll> cur;
int main()
{
    int n, a, b;
    ll ans = -1000000000000000000;
    cin >> n >> a >> b;
    for(int i = 0; i < n; i ++)
    {
        cin >> nums[i];
        pre[i + 1] = pre[i] + nums[i];
    }
    cur.insert(0);
    for(int i = a; i <= b; i ++)
    {
        ans = max(ans, pre[i] - *cur.begin());
        if(a != b) cur.insert(pre[i - a + 1]);
    }
    for(int i = b + 1; i <= n; i ++)
    {
        cur.erase(cur.find(pre[i - b - 1]));
        cur.insert(pre[i - a]);
        ans = max(ans, pre[i] - *cur.begin());
    }
    cout << ans << "\n";
}
