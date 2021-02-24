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
 
int sum(int arr[], int idx)
{
    int ans = 0;
    idx ++;
    while(idx > 0)
    {
        ans += arr[idx];
        idx -= idx & (-idx);
    }
    return ans;
}
void update(int arr[], int idx, int val, int size)
{
    idx ++;
    while(idx <= size)
    {
        arr[idx] += val;
        idx += idx & (-idx);
    }
}
int bit[200010];
set<int> nums;
int bs(int l, int r, int idx)
{
    int mid = (l + r) / 2;
    if(l == r) return mid + 1;
    if(l == r - 1)
    {
        if(sum(bit, r) == idx) return r + 1;
        return r;
    }
    if(sum(bit, mid) <= idx) return bs(mid, r, idx);
    return bs(l, mid - 1, idx);
}
int main()
{
    int n, k, idx;
    set<int>::iterator cur, nex;
    cin >> n >> k;
    // Store BIT with values and binary search for value at index i, because for any value I can check its index in the 'set' (so O(log^2(n)) time)
    for(int i = 1; i <= n; i ++)
    {
        nums.insert(i);
        update(bit, i, 1, n + 5);
    }
    cur = prev(nums.end()); cur ++;
    for(int i = 0; i < n; i ++)
    {
        if(cur == nums.end()) cur = nums.begin();
        idx = sum(bit, *cur - 1);
        idx = (idx + k) % (int)nums.size();
        cur = nums.find(bs(0, n, idx));
        cout << *cur << " ";
        nex = cur;
        nex ++;
        if(nex == nums.end()) nex = nums.begin();
        nums.erase(cur);
        update(bit, *cur, -1, n + 5);
        cur = nex;
    }
    cout << "\n";
}
