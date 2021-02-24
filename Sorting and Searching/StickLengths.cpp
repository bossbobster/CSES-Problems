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
 
long long nums[200010];
int main()
{
    long long n, mid, ans = 0;
    cin >> n;
    for(int i = 0; i < n; i ++)
        cin >> nums[i];
    sort(nums, nums + n);
    if(n % 2 == 1) mid = nums[n / 2];
    else mid = (nums[n / 2 - 1] + nums[n / 2]) / 2;
    for(int i = 0; i < n; i ++)
        ans += abs(nums[i] - mid);
    cout << ans << "\n";
}
