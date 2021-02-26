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

ll sum(ll arr[], int idx)
{
    ll ans = 0;
    idx ++;
    while(idx > 0)
    {
        ans += arr[idx];
        idx -= idx & (-idx);
    }
    return ans;
}
void update(ll arr[], int idx, ll val, int size)
{
    idx ++;
    while(idx <= size)
    {
        arr[idx] += val;
        idx += idx & (-idx);
    }
}
ll bit[200010];
ll nums[200010];
int main()
{
    int n, q, a, b, c;
    cin >> n >> q;
    for(int i = 0; i < n; i ++)
    {
        cin >> nums[i];
        update(bit, i, nums[i], n);
    }
    for(int i = 0; i < q; i ++)
    {
        cin >> a >> b >> c;
        if(a == 1)
        {
            update(bit, b - 1, c - nums[b - 1], n);
            nums[b - 1] = c;
        }
        else
            cout << sum(bit, c - 1) - sum(bit, b - 2) << "\n";
    }
}
