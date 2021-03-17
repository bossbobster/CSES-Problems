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
typedef pair<pii, int> piii;
typedef long long ll;
typedef pair<ll, ll> pll;
//#define max(n, m) ((n>m)?n:m)
//#define min(n, m) ((n<m)?n:m)
#define f first
#define s second

int main()
{
    int n, x, ans;
    cin >> n;
    for(int i = 0; i < n; i ++)
    {
        cin >> x;
        ans = 0;
        for(int j = 1; j <= sqrt(x); j ++)
            if(x % j == 0)
            {
                ans ++;
                if(x/j != j) ans ++;
            }
        cout << ans << "\n";
    }
}
