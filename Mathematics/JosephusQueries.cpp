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

set<ll> pos;
int main()
{
    ll q, n, k, cur, mult = 2;
    cin >> q;
    for(int i = 0; i < q; i ++)
    {
        cin >> n >> k;
        if(n == 1) { cout << "1\n"; continue; }
        if(n == 2) { cout << ((k == 1)?"2\n":"1\n"); continue; }
        pos.clear(); pos.insert(1); mult = 2; cur = 0;
        while(k > (n - cur) / mult)
        {
            k -= ((n - cur) / mult) + 1;
            pos.insert(*pos.begin() + mult);
            cur += (n - cur) / mult * mult;
            if(cur + mult/2 > n) { cur = *prev(pos.end()); pos.erase(prev(pos.end())); }
            else { cur = *pos.begin(); pos.erase(pos.begin()); }
            mult *= 2;
        }
        cur += k * mult;
        if(cur > n) cur -= mult/2;
        cout << cur << "\n";
    }
}
