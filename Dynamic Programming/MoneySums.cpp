#include <iostream>
#include <fstream>
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

bitset<100010> dp;
int nums[110];
int main()
{
    
    int n, sum = 0;
    cin >> n;
    for(int i = 0; i < n; i ++)
    {
        cin >> nums[i];
        sum += nums[i];
    }
    dp[0] = true;
    for(int i = 0; i < n; i ++)
        for(int j = sum; j >= nums[i]; j --)
            dp[j] = max(dp[j], dp[j - nums[i]]);
    cout << dp.count() - 1 << "\n";
    for(int i = 1; i <= sum; i ++)
        if(dp[i])
            cout << i << " ";
    cout << "\n";
}
