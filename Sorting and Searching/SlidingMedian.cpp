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
 
multiset<int> l;
multiset<int> r;
vector<int> first;
int nums[200010];
int main()
{
    int n, k;
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
    cout << *prev(l.end()) << " ";
    for(int i = k; i < n; i ++)
    {
        if(nums[i - k] <= *prev(l.end()))
            l.erase(l.find(nums[i - k]));
        else
            r.erase(r.find(nums[i - k]));
        r.insert(nums[i]);
        if(r.size() && l.size() && *r.begin() < *prev(l.end()))
        {
            r.insert(*prev(l.end())); l.erase(prev(l.end()));
            l.insert(*r.begin()); r.erase(r.begin());
        }
        if(r.size() > l.size())
        {
            l.insert(*r.begin());
            r.erase(r.begin());
        }
        cout << *prev(l.end()) << " ";
    }
    cout << "\n";
}
