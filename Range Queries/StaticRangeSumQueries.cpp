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
long long pre[200010];
int main()
{
    int n, q, a, b;
    cin >> n >> q;
    for(int i = 0; i < n; i ++)
    {
        cin >> nums[i];
        pre[i + 1] = pre[i] + nums[i];
    }
    for(int i = 0; i < q; i ++)
    {
        cin >> a >> b;
        cout << pre[b] - pre[a - 1] << "\n";
    }
}
