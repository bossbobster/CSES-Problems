#include <iostream>
#include <string.h>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <bitset>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#pragma GCC optimize ("O2")
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
using namespace std;
typedef pair<int, int> pii;
typedef pair<int, string> pis;
typedef pair<int, char> pic;
typedef pair<pii, int> piii;
typedef pair<double, double> pdd;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<ll, ll> pll;
typedef pair<int, ll> pil;
typedef pair<ull, ull> pull;
//#define max(n, m) ((n>m)?n:m)
//#define min(n, m) ((n<m)?n:m)
#define f first
#define s second
#define input() ios_base::sync_with_stdio(0);cin.tie(0);

bitset<3010> arr[3010];
int main()
{
    input();
    int n, tmp;
    ll ans = 0;
    cin >> n;
    string st;
    for(int i = 0; i < n; i ++)
    {
        cin >> st;
        for(int j = 0; j < n; j ++)
            if(st[j] == '1')
                arr[i][j] = 1;
    }
    for(int i = 1; i < n; i ++)
        for(int j = 0; j < i; j ++)
        {
            tmp = (arr[i]&arr[j]).count();
            ans += tmp * (tmp-1) / 2;
        }
    cout << ans << "\n";
}
