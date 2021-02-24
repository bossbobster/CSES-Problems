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
multiset<int> dist;
int main()
{
    int x, n, num, aft, bef;
    set<int>::iterator it;
    cin >> x >> n;
    nums.insert(0); nums.insert(x); dist.insert(x);
    for(int i = 0; i < n; i ++)
    {
        cin >> num;
        nums.insert(num);
        it = nums.upper_bound(num);
        aft = *it; it --; it --;
        bef = *it;
        dist.erase(dist.find(aft - bef));
        dist.insert(aft - num); dist.insert(num - bef);
        cout << *dist.rbegin() << " ";
    }
    cout << "\n";
}
