#include <iostream>
#include <string.h>
#include <fstream>
#include <stdio.h>
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
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
using namespace std;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef long long ll;
typedef pair<ll, ll> pll;
//#define max(n, m) ((n>m)?n:m)
//#define min(n, m) ((n<m)?n:m)
#define f first
#define s second

int n;
int tree[400010];
int nums[200010];
void makeTree(int nums[])
{
    for(int i = 0; i < n; i ++)
        tree[n + i] = nums[i];
    for(int i = n - 1; i > 0; -- i)
        tree[i] = max(tree[i << 1], tree[i << 1 | 1]);
}
void update(int idx, int val)
{
    tree[idx + n] = val;
    idx += n;
    for(int i = idx; i > 1; i >>= 1)
        tree[i >> 1] = max(tree[i], tree[i ^ 1]);
}
int maxQ(int l, int r) // inclusive l, exclusive r
{
    int ans = 0;
    for(l += n, r += n; l < r; l >>= 1, r >>= 1)
    {
        if(l & 1)
            ans = max(ans, tree[l ++]);
        if(r & 1)
            ans = max(ans, tree[-- r]);
    }
    return ans;
}
int bs(int l, int r, int t)
{
    int mid = (l + r) / 2, num = maxQ(0, mid);
    if(l == r) return mid;
    if(num < t) return bs(mid + 1, r, t);
    return bs(l, mid, t);
}
int main()
{
    int m, a, ans;
    cin >> n >> m;
    for(int i = 0; i < n; i ++)
        cin >> nums[i];
    makeTree(nums);
    for(int i = 0; i < m; i ++)
    {
        cin >> a;
        ans = bs(1, n + 1, a);
        if(ans > n) cout << "0 ";
        else
        {
            cout << ans << " ";
            update(ans - 1, nums[ans - 1] - a);
            nums[ans - 1] = nums[ans - 1] - a;
        }
    }
    cout << "\n";
}
