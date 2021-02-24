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
 
int nums[200010];
map<int, int> pos;
int main()
{
    int n, pre = 2000000000, ans = 0;
    cin >> n;
    for(int i = 0; i < n; i ++)
    {
        cin >> nums[i];
        pos[nums[i]] = i;
    }
    for(int i = 1; i <= n; i ++)
    {
        if(pos[i] < pre) ans ++;
        pre = pos[i];
    }
    cout << ans << "\n";
}
