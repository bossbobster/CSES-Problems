#include <iostream>
#include <string.h>
#include <random>
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
#include <complex>
#include <valarray>
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
using namespace std;
typedef pair<int, int> pii;
typedef pair<int, string> pis;
typedef pair<string, string> pss;
typedef pair<int, char> pic;
typedef pair<pii, int> piii;
typedef pair<double, double> pdd;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<ll, ll> pll;
typedef pair<int, ll> pil;
typedef pair<ull, ull> pull;
typedef complex<double> cd;
//#define max(n, m) ((n>m)?n:m)
//#define min(n, m) ((n<m)?n:m)
#define f first
#define s second
#define input() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

ll n, m, k, a, b, c, i, j;
vector<vector<ll>> mat, cur;
vector<vector<ll>> mult(vector<vector<ll>> v1, vector<vector<ll>> v2)
{
    vector<vector<ll>> ans;
    ans.resize(n, vector<ll>(n));
    for(int i = 0; i < n; i ++)
        for(int j = 0; j < n; j ++)
            ans[i][j] = 2000000000000000000;
    for(i = 0; i < n; i ++)
        for(j = 0; j < n; j ++)
            for(k = 0; k < n; k ++)
                ans[i][j] = min(ans[i][j], v1[i][k] + v2[k][j]);
    return ans;
}
void ex(int power)
{
    while(power)
    {
        if(power & 1)
            cur = mult(cur, mat);
        mat = mult(mat, mat);
        power >>= 1;
    }
}
int main()
{
    input();
    cin >> n >> m >> k;
    mat.resize(n, vector<ll>(n)); cur.resize(n, vector<ll>(n));
    for(int i = 0; i < n; i ++)
        for(int j = 0; j < n; j ++)
            mat[i][j] = cur[i][j] = 2000000000000000000;
    for(i = 0; i < m; i ++)
    {
        cin >> a >> b >> c; a--; b--;
        mat[a][b] = min(mat[a][b], c); cur[a][b] = min(cur[a][b], c);
    }
    ex(k-1);
    cout << ((cur[0][n-1]==2000000000000000000)?-1:cur[0][n-1]) << "\n";
}
