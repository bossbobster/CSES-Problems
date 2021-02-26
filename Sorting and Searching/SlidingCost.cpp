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

multiset<ll> l;
multiset<ll> r;
vector<ll> first;
ll nums[200010];
int main()
{
    ll n, k, sumL = 0, sumR = 0;
    cin >> n >> k;
    for(int i = 0; i < n; i ++)
        cin >> nums[i];
    for(int i = 0; i < k; i ++)
        first.push_back(nums[i]);
    sort(first.begin(), first.end());
    for(int i = 0; i < k / 2; i ++)
        l.insert(first[i]);
    for(int i = k / 2; i < k; i ++)
        r.insert(first[i]);
    if(l.size() < r.size())
    {
        l.insert(*r.begin());
        r.erase(r.begin());
    }
    for(auto cur : l)
        sumL += cur;
    for(auto cur : r)
        sumR += cur;
    cout << ((*prev(l.end()) * l.size() - sumL) + (sumR - *prev(l.end()) * r.size())) << " ";
    for(int i = (int)k; i < (int)n; i ++)
    {
        if(nums[i - k] <= *prev(l.end()))
        {
            l.erase(l.find(nums[i - k]));
            sumL -= nums[i - k];
        }
        else
        {
            r.erase(r.find(nums[i - k]));
            sumR -= nums[i - k];
        }
        r.insert(nums[i]);
        sumR += nums[i];
        if(r.size() && l.size() && *r.begin() < *prev(l.end()))
        {
            sumR += *prev(l.end()); sumR -= *r.begin();
            sumL -= *prev(l.end()); sumL += *r.begin();
            r.insert(*prev(l.end())); l.erase(prev(l.end()));
            l.insert(*r.begin()); r.erase(r.begin());
        }
        if(r.size() > l.size())
        {
            sumR -= *r.begin(); sumL += *r.begin();
            l.insert(*r.begin()); r.erase(r.begin());
        }
        cout << ((*prev(l.end()) * l.size() - sumL) + (sumR - *prev(l.end()) * r.size())) << " ";
    }
    cout << "\n";
}
