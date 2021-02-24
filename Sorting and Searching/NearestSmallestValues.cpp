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
 
int nums[200010];
stack<int> pre;
int ans[200010];
int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i ++)
        cin >> nums[i];
    pre.push(0);
    for(int i = 1; i < n; i ++)
    {
        while(!pre.empty() && nums[i] <= nums[pre.top()]) pre.pop();
        ans[i] = (pre.empty()?0:(pre.top() + 1));
        pre.push(i);
    }
    for(int i = 0; i < n; i ++)
        cout << ans[i] << " ";
}
