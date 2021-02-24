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
int main()
{
    int n;
    set<int>::iterator cur, nex;
    cin >> n;
    for(int i = 1; i <= n; i ++)
        nums.insert(i);
    cur = prev(nums.end()); cur ++;
    for(int i = 0; i < n; i ++)
    {
        if(cur == nums.end()) cur = nums.begin();
        cur ++;
        if(cur == nums.end()) cur = nums.begin();
        cout << *cur << " ";
        nex = cur;
        nex ++;
        if(nex == nums.end()) nex = nums.begin();
        nums.erase(cur);
        cur = nex;
    }
    cout << "\n";
}
