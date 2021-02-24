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
 
int main()
{
    long long n, num, cur = 0, ans = -2000000000000000;
    cin >> n;
    for(int i = 0; i < n; i ++)
    {
        cin >> num;
        cur += num;
        ans = max(ans, cur);
        if(cur < 0) cur = 0;
    }
    cout << ans << "\n";
}
