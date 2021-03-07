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
#define max(n, m) ((n>m)?n:m)
#define min(n, m) ((n<m)?n:m)
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
        tree[i] = tree[i << 1] ^ tree[i << 1 | 1];
}
void update(int idx, int val)
{
    tree[idx + n] = val;
    idx += n;
    for(int i = idx; i > 1; i >>= 1)
        tree[i >> 1] = tree[i] ^ tree[i ^ 1];
}
int minQ(int l, int r) // inclusive l, exclusive r
{
    int ans = 0;
    for(l += n, r += n; l < r; l >>= 1, r >>= 1)
    {
        if(l & 1)
            ans = ans ^ tree[l ++];
        if(r & 1)
            ans = ans ^ tree[-- r];
    }
    return ans;
}
int main()
{
    int q, a, b;
    cin >> n >> q;
    for(int i = 0; i < n; i ++)
        cin >> nums[i];
    makeTree(nums);
    for(int i = 0; i < q; i ++)
    {
        cin >> a >> b;
        cout << minQ(a - 1, b) << "\n";
    }
}
