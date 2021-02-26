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
 
int pre[200010][35];
int nums[200010];
 
void sparse(int n)
{
    for(int i = 0; i < n; i ++)
        pre[i][0] = nums[i];
    for(int i = 1; i <= floor(log2(n)); i ++)
        for(int j = 0; j <= n - (1 << i); j ++)
            pre[j][i] = min(pre[j][i - 1], pre[j + (1 << (i - 1))][i - 1]);
}
int minQ(int l, int r)
{
    int log = floor(log2(r - l + 1));
    return min(pre[l][log], pre[r - (1 << log) + 1][log]);
}
int main()
{
    int n, q, a, b;
    cin >> n >> q;
    for(int i = 0; i < n; i ++)
        cin >> nums[i];
    sparse(n);
    for(int i = 0; i < q; i ++)
    {
        cin >> a >> b;
        cout << minQ(a - 1, b - 1) << "\n";
    }
}
