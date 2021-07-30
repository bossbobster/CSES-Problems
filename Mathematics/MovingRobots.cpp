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
#define input() ios_base::sync_with_stdio(0);cin.tie(0);

vector<pii> adj[8][8];
int dr[4] = {1, 0, -1, 0}, dc[4] = {0, 1, 0, -1};
ld dp[8][8];
ld nums[8][8];
ld ansV[8][8];
int main()
{
    input();
    int k, r, c;
    ld ans = 0;
    cin >> k;
    for(int i = 0; i < 8; i ++)
        for(int j = 0; j < 8; j ++)
            for(int k = 0; k < 4; k ++)
            {
                r = i + dr[k]; c = j + dc[k];
                if(r >= 0 && r < 8 && c >= 0 && c < 8)
                    adj[i][j].push_back({r, c});
            }
    for(int i = 0; i < 8; i ++)
        for(int j = 0; j < 8; j ++)
            ansV[i][j] = 1;
    for(int curR = 0; curR < 8; curR ++)
        for(int curC = 0; curC < 8; curC ++)
        {
            for(int r = 0; r < 8; r ++)
                for(int c = 0; c < 8; c ++)
                    dp[r][c] = 0;
            dp[curR][curC] = 1;
            for(int i = 0; i < k; i ++)
            {
                for(int r = 0; r < 8; r ++)
                    for(int c = 0; c < 8; c ++)
                        nums[r][c] = 0;
                for(int r = 0; r < 8; r ++)
                    for(int c = 0; c < 8; c ++)
                        for(auto it : adj[r][c])
                            nums[r][c] += (dp[it.f][it.s]/(ld)(adj[it.f][it.s].size()));
                for(int r = 0; r < 8; r ++)
                    for(int c = 0; c < 8; c ++)
                        dp[r][c] = nums[r][c];
            }
            for(int r = 0; r < 8; r ++)
                for(int c = 0; c < 8; c ++)
                    ansV[r][c] *= (1.0-dp[r][c]);
        }
    for(int i = 0; i < 8; i ++)
        for(int j = 0; j < 8; j ++)
            ans += ansV[i][j];
    cout << fixed << setprecision(6) << ans << '\n';
}
