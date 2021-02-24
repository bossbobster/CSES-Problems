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
 
set<int> nums;
map<int, int> cnt;
int main()
{
    int n, m, num;
    set<int>::iterator it;
    cin >> n >> m;
    for(int i = 0; i < n; i ++)
    {
        cin >> num; nums.insert(num); cnt[num] ++;
    }
    for(int i = 0; i < m; i ++)
    {
        cin >> num;
        it = nums.upper_bound(num);
        if(it == nums.begin()) { cout << -1 << "\n"; continue; }
        it --;
        cout << *it << "\n";
        cnt[*it] --;
        if(cnt[*it] == 0) nums.erase(*it);
    }
}
