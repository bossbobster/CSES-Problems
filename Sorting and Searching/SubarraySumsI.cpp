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
int main()
{
    ll n, x, cur = 0, idx1 = 0, idx2 = 0, ans = 0;
    cin >> n >> x;
    for(int i = 0; i < n; i ++)
        cin >> nums[i];
    while(idx2 <= n)
    {
        if(cur < x) { cur += nums[idx2]; idx2 ++; }
        else if(cur == x) { ans ++; cur += nums[idx2]; idx2 ++; }
        else { cur -= nums[idx1]; idx1 ++; }
    }
    cout << ans << "\n";
}
