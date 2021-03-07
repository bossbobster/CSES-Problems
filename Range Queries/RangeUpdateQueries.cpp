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
    updateB(arr1, l, val, size);
    updateB(arr1, r + 1, -1 * val, size);
    updateB(arr2, l, val * (l - 1), size);
    updateB(arr2, r + 1, -1 * val * r, size);
}
ll bit1[200010];
ll bit2[200010];
int main()
{
    ll n, q, nm, type, a, b, c;
    cin >> n >> q;
    for(int i = 0; i < n; i ++)
    {
        cin >> nm;
        update(bit1, bit2, i, i, nm, (int)n);
    }
    for(int i = 0; i < q; i ++)
    {
        cin >> type;
        if(type == 1)
        {
            cin >> a >> b >> c;
            update(bit1, bit2, (int)a - 1, (int)b - 1, c, (int)n);
        }
        else
        {
            cin >> a;
            cout << sum(bit1, bit2, (int)a - 1, (int)a - 1) << "\n";
        }
    }
}
