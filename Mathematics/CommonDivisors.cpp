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

int cnt[1000010];
int main()
{
    int n, x, mults, mx = 0;
    cin >> n;
    for(int i = 0; i < n; i ++)
    {
        cin >> x; mx = max(mx, x);
        cnt[x] ++;
    }
    for(int i = mx; i >= 1; i --)
    {
        mults = 0;
        for(int cur = i; cur <= mx; cur += i)
        {
            if(cnt[cur] >= 2) { cout << cur << "\n"; return 0; }
            else if(cnt[cur] == 1) mults ++;
            if(mults >= 2) { cout << i << "\n"; return 0; }
        }
    }
    cout << "1\n";
}
