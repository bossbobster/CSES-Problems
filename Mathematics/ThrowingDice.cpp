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

int mod = 1000000007;
ll mat[6][6] = {{1, 1, 1, 1, 1, 1}, {1, 0, 0, 0, 0, 0}, {0, 1, 0, 0, 0, 0}, {0, 0, 1 ,0 ,0 ,0}, {0, 0, 0, 1, 0, 0}, {0, 0, 0, 0, 1, 0}}, cur[6] = {32, 16, 8, 4, 2, 1}, temp[6][6], temp1[6];
void ex(ll power)
{
    while(power)
    {
        if(power & 1)
        {
            for(int i = 0; i < 6; i ++) temp1[i] = cur[i];
            for(int i = 0; i < 6; i ++)
            {
                cur[i] = 0;
                for(int k = 0; k < 6; k ++)
                    cur[i] = (cur[i] + (temp1[k] * mat[i][k])) % mod;
            }
        }
        for(int i = 0; i < 6; i ++) for(int j = 0; j < 6; j ++) temp[i][j] = mat[i][j];
        for(int i = 0; i < 6; i ++)
            for(int j = 0; j < 6; j ++)
            {
                mat[i][j] = 0;
                for(int k = 0; k < 6; k ++)
                    mat[i][j] = (mat[i][j] + (temp[i][k] * temp[k][j])) % mod;
            }
        power /= 2;
    }
}
int main()
{
    ll n;
    cin >> n;
    if(n <= 6) { cout << cur[6-n] << "\n"; return 0; }
    ex(n-6);
    cout << cur[0] << "\n";
}
