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
//ulng namespace __gnu_pbds;
using namespace std;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef long long ll;
typedef pair<ll, ll> pll;
#define max(n, m) ((n>m)?n:m)
//#define min(n, m) ((n<m)?n:m)
#define f first
#define s second

struct qr
{
    char c;
    int a, b;
};
struct chash { /// use most bits rather than just the lowest ones
    const uint64_t C = ll(2e18*(3.14))+71; // large odd number
    const int RANDOM = rand(); // random 32-bit number
    ll operator()(ll x) const {
        // https://gcc.gnu.org/onlinedocs/gcc/Other-Builtins.html
        return __builtin_bswap64((x^RANDOM)*C);
    }
};
int nums[200010];
unordered_set<int, chash> st;
unordered_map<int, int, chash> m;
vector<int> v;
qr qs[200010];
int bit[1000010];
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
int main()
{
    int n, q;
    cin >> n >> q;
    for(int i = 0; i < n; i ++)
    {
        cin >> nums[i];
        if(st.find(nums[i]) == st.end()) { v.push_back(nums[i]); st.insert(nums[i]); }
    }
    for(int i = 0; i < q; i ++)
    {
        cin >> qs[i].c >> qs[i].a >> qs[i].b;
        if(st.find(qs[i].b) == st.end()) { v.push_back(qs[i].b); st.insert(qs[i].b); }
        if(qs[i].c == '?' && st.find(qs[i].a) == st.end()) { v.push_back(qs[i].a); st.insert(qs[i].a); }
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < v.size(); i ++)
        m[v[i]] = i;
    for(int i = 0; i < n; i ++)
    {
        nums[i] = m[nums[i]];
        update(bit, nums[i], 1, (int)st.size());
    }
    for(int i = 0; i < q; i ++)
    {
        if(qs[i].c == '?') qs[i].a = m[qs[i].a];
        qs[i].b = m[qs[i].b];
        if(qs[i].c == '?')
            cout << sum(bit, qs[i].b) - sum(bit, qs[i].a-1) << "\n";
        else
        {
            update(bit, qs[i].b, 1, (int)st.size());
            update(bit, nums[qs[i].a-1], -1, (int)st.size());
            nums[qs[i].a-1] = qs[i].b;
        }
    }
}
