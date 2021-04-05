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
typedef pair<string, string> pss;
typedef pair<pii, int> piii;
typedef pair<string, int> psi;
typedef long long ll;
typedef pair<ll, ll> pll;
//#define max(n, m) ((n>m)?n:m)
//#define min(n, m) ((n<m)?n:m)
#define f first
#define s second

bitset<40> nums[20010];
int main()
{
    int n, k, ans = 2000000000;
    string st;
    cin >> n >> k;
    for(int i = 0; i < n; i ++)
    {
        cin >> st;
        for(int j = 0; j < k; j ++)
            if(st[j] == '1')
                nums[i][j] = 1;
    }
    for(int i = 0; i < n-1; i ++)
        for(int j = i + 1; j < n; j ++)
            ans = min(ans, (int)(nums[i] ^ nums[j]).count());
    cout << ans << "\n";
}
