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
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
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
struct st
{
    int a, b, idx;
};
bool comp1(st s1, st s2)
{
    if(s1.b == s2.b) return s1.a > s2.a;
    return s1.b < s2.b;
}
bool comp2(st s1, st s2)
{
    if(s1.a == s2.a) return s1.b > s2.b;
    return s1.a < s2.a;
}
unordered_map<int, int> hsh;
set<int> coords;
st nums[200010];
int bit[400010];
int bit2[400010];
int ans1[200010];
int ans2[200010];
int main()
{
    int n, indx = 0;
    cin >> n;
    for(int i = 0; i < n; i ++)
    {
        cin >> nums[i].a >> nums[i].b;
        coords.insert(nums[i].a); coords.insert(nums[i].b);
        nums[i].idx = i;
    }
    sort(nums, nums + n, comp1);
    for(auto cur : coords)
    {
        hsh[cur] = indx;
        indx ++;
    }
    for(int i = 0; i < n; i ++)
    {
        ans1[nums[i].idx] = sum(bit, hsh[nums[i].b]) - sum(bit, hsh[nums[i].a] - 1);
        update(bit, hsh[nums[i].a], 1, (int)coords.size());
    }
    sort(nums, nums + n, comp2);
    for(int i = 0; i < n; i ++)
    {
        ans2[nums[i].idx] = sum(bit2, (int)coords.size() - 1) - sum(bit2, hsh[nums[i].b] - 1);
        update(bit2, hsh[nums[i].b], 1, (int)coords.size());
    }
    for(int i = 0; i < n; i ++)
        cout << ans1[i] << " ";
    cout << "\n";
    for(int i = 0; i < n; i ++)
        cout << ans2[i] << " ";
    cout << "\n";
    return 0;
}
