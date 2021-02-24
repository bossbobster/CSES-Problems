#include <iostream>
#include <iomanip>
#include <algorithm>
#include <math.h>
#include <vector>
#include <queue>
#include <bitset>
#include <map>
#include <set>
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
    int n, ans = 0, cur = 1;
    cin >> n;
    for(int i = 0; i < 13; i ++)
    {
        cur *= 5;
        ans += n / cur;
    }
    cout << ans << "\n";
}
