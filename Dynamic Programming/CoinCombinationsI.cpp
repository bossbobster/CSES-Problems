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
 
int coins[110];
int vals[1000010];
int main()
{
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; i ++)
        cin >> coins[i];
    vals[0] = 1;
    for(int i = 1; i <= k; i ++)
        for(int j = 0; j < n; j ++)
            if(i - coins[j] == 0 || (i - coins[j] > -1 && vals[i - coins[j]] != 0))
                vals[i] = (vals[i] + vals[i - coins[j]]) % 1000000007;
    cout << vals[k] << "\n";
}
