#include <iostream>
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
#define max(n, m) ((n>m)?n:m)
#define min(n, m) ((n<m)?n:m)
#define f first
#define s second

ll dp[20][10]; // size and last digit (for numbers with less digits than target)
pll dp2[20][10]; // for numbers with same number of digits as target
vector<int> adj[10];
ll upto(ll x)
{
    ll ans = 0;
    if(x == -1) return -1;
    if(x == 0) return 0;
    vector<int> mx; ll tmp = x;
    while(tmp > 0)
    {
        mx.push_back(tmp % 10);
        tmp /= 10;
    }
    if(mx.size() == 1) return x;
    for(int i = 0; i < mx.size() / 2; i ++) swap(mx[i], mx[mx.size() - i - 1]);
    for(int i = 0; i < 20; i ++)
        for(int j = 0; j < 10; j ++)
            dp[i][j] = dp2[i][j].f = dp2[i][j].s = 0;
    for(int i = 1; i < 10; i ++)
        if(mx.size() > 1 || i <= mx[0])
        {
            dp[1][i] = 1; ans ++;
        }
    for(int i = 1; i < 10; i ++)
        if(i < mx[0])
            dp2[1][i] = {0, 1};
    dp2[1][mx[0]] = {1, 0};
    for(int i = 2; i < mx.size(); i ++)
        for(int j = 0; j < 10; j ++)
        {
            for(auto pre : adj[j])
                dp[i][j] += dp[i - 1][pre];
            ans += dp[i][j];
        }
    for(int i = 2; i <= mx.size(); i ++)
        for(int j = 0; j < 10; j ++)
        {
            for(auto pre : adj[j])
            {
                if(pre == mx[i - 2] && j == mx[i - 1]) { dp2[i][j].f += dp2[i-1][pre].f; }
                if(pre == mx[i - 2] && j < mx[i - 1]) { dp2[i][j].s += dp2[i-1][pre].f; }
                dp2[i][j].s += dp2[i - 1][pre].s;
            }
        }
    for(int i = 0; i < 10; i ++) ans += (dp2[mx.size()][i].f + dp2[mx.size()][i].s);
    return ans;
}
int main()
{
    ll a, b;
    cin >> a >> b;
    for(int i = 0; i < 10; i ++)
        for(int j = 0; j < 10; j ++)
            if(i != j)
                adj[i].push_back(j);
    cout << upto(b) - upto(a - 1) << "\n";
}
