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
ll sumB(ll arr[], int idx)
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
void updateB(ll arr[], int idx, ll val, int size)
{
    idx ++;
    while(idx <= size)
    {
        arr[idx] += val;
        idx += idx & (-idx);
    }
}
ll sum(ll arr1[], ll arr2[], int l, int r)
{
    return (((sumB(arr1, r) * r) - (sumB(arr2, r))) - ((sumB(arr1, l - 1) * (l - 1)) - (sumB(arr2, l - 1))));
}
void update(ll arr1[], ll arr2[], int l, int r, ll val, int size)
{
    if(l > r) return;
    updateB(arr1, l, val, size);
    updateB(arr1, r + 1, -1 * val, size);
    updateB(arr2, l, val * (l - 1), size);
    updateB(arr2, r + 1, -1 * val * r, size);
}
ll bit1[200010];
ll bit2[200010];
ll nums[200010];
int bs(int l, int r, int t)
{
    int mid = (l + r + 1) / 2, cur = sum(bit1, bit2, mid, mid);
    if(l == r) return mid;
    if(cur <= t) return bs(mid, r, t);
    return bs(l, mid - 1, t);
}
int main()
{
    int idx, ans;
    cin >> n;
    for(int i = 0; i < n; i ++)
    {
        cin >> nums[i];
        update(bit1, bit2, i, i, i, n);
    }
    for(int i = 0; i < n; i ++)
    {
        cin >> idx; idx --;
        ans = bs(0, n - 1, idx);
        cout << nums[ans] << " ";
        update(bit1, bit2, ans + 1, n - 1, -1, n);
    }
    cout << "\n";
}
