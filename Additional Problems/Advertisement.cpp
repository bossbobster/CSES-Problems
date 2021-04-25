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
typedef pair<ull, ull> pull;
//#define max(n, m) ((n>m)?n:m)
//#define min(n, m) ((n<m)?n:m)
#define f first
#define s second

stack<pll> st;
ll heights[200010];
int r[200010];
int l[200010];
int main()
{
    int n;
    ll ans = 0;
    cin >> n;
    for(int i = 0; i < n; i ++)
        cin >> heights[i];
    memset(l, -1, sizeof(l)); for(int i = 0; i < n; i ++) r[i] = n;
    for(int i = 0; i < n; i ++)
    {
        while(!st.empty() && st.top().first > heights[i])
        {
            r[st.top().second] = i;
            st.pop();
        }
        st.push({heights[i], i});
    }
    while(!st.empty()) st.pop();
    for(int i = n - 1; i >= 0; i --)
    {
        while(!st.empty() && st.top().first > heights[i])
        {
            l[st.top().second] = i;
            st.pop();
        }
        st.push({heights[i], i});
    }
    for(int i = 0; i < n; i ++)
        ans = max(ans, heights[i] * (r[i] - l[i] - 1));
    cout << ans << "\n";
}
