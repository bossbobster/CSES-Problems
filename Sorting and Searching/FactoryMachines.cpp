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
 
unsigned long long n, t;
unsigned long long nums[200010];
unsigned long long bs(unsigned long long l, unsigned long long r)
{
    unsigned long long mid = (l + r) / 2, cur = 0;
    if(l == r) return mid;
    for(int i = 0; i < n; i ++)
        cur += mid / nums[i];
    if(cur >= t) return bs(l, mid);
    return bs(mid + 1, r);
}
int main()
{
    cin >> n >> t;
    for(int i = 0; i < n; i ++)
        cin >> nums[i];
    cout << bs(1, 1000000000000000001) << "\n";
}
