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
#define input(x) ios_base::sync_with_stdio(x); cin.tie(x);

int to[200010][30];
int pw[30];
int main()
{
    input(0);
    int n, q, a, b, cur;
    cin >> n >> q;
    pw[0] = 1;
    for(int i = 1; i < 30; i ++)
        pw[i] = pw[i-1]*2;
    for(int i = 0; i <= n; i ++) for(int j = 0; j < 30; j ++) to[i][j] = -1;
    for(int i = 1; i < n; i ++)
        cin >> to[i+1][0];
    for(int i = 1; i < 30; i ++)
        for(int j = 1; j <= n; j ++)
        {
            if(to[j][i-1] == -1) to[j][i] = -1;
            else to[j][i] = to[to[j][i-1]][i-1];
        }
    while(q--)
    {
        cin >> a >> b;
        cur = log2(n);
        while(b > 0)
        {
            if(pw[cur] <= b) { b -= pw[cur]; a = to[a][cur]; }
            if(a == -1) break;
            cur--;
        }
        cout << a << "\n";
    }
}
