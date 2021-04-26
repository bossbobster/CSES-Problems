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

int n, q, a, b; ll cost;
ll nums[200010], pre[200010];
pll rr[200010], to[200010][30];
stack<int> st;
int main()
{
    scanf("%d %d", &n, &q);
    for(int i = 0; i < n; i ++)
    {
        scanf("%lld", &nums[i]);
        pre[i+1] = pre[i] + nums[i];
    }
    for(int i = 0; i < n; i ++)
    {
        while(!st.empty() && nums[i] > nums[st.top()])
        {
            rr[st.top()] = {i, nums[st.top()] * (i - st.top()) - (pre[i] - pre[st.top()])};
            st.pop();
        }
        st.push(i);
    }
    while(!st.empty())
    {
        rr[st.top()] = {n, nums[st.top()] * (n - st.top()) - (pre[n] - pre[st.top()])};
        st.pop();
    }
    for(int i = 0; i <= n; i ++) to[i][0] = rr[i];
    for(int i = 0; i < 30; i ++) to[n][i] = {n, 0};
    for(int j = 1; j < 30; j ++)
        for(int i = 0; i < n; i ++)
            to[i][j] = { to[to[i][j-1].f][j-1].f, to[i][j-1].s + to[to[i][j-1].f][j-1].s };
    while(q--)
    {
        scanf("%d %d", &a, &b); a--; b--;
        if(a == b) {printf("0\n"); continue;}
        cost = 0;
        for(int i = 29; i >= 0; i --)
            if(to[a][i].f < b)
            {
                cost += to[a][i].s;
                a = to[a][i].f;
            }
        if(rr[a].f == b) printf("%lld\n", cost + nums[a] * (b - a - 1) - (pre[b] - pre[a+1]));
        else printf("%lld\n", cost + nums[a] * (b - a) - (pre[b+1] - pre[a+1]));
    }
    return 0;
}
