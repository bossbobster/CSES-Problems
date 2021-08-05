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

char nums[1010][1010];
int cnt[1010][1010];
stack<pii> st;
int r[1010];
int l[1010];
int main()
{
    input();
    int n, m, ans = 0;
    cin >> n >> m;
    for(int i = 0; i < n; i ++)
        for(int j = 0; j < m; j ++)
            cin >> nums[i][j];
    for(int i = 0; i < m; i ++)
        if(nums[0][i] == '.')
            cnt[0][i] = 1;
    for(int i = 1; i < n; i ++)
        for(int j = 0; j < m; j ++)
        {
            if(nums[i][j] == '.')
                cnt[i][j] = cnt[i-1][j]+1;
            else
                cnt[i][j] = 0;
        }
    ans = 0;
    for(int j = 0; j < n; j ++)
    {
        for(int i = 0; i < m; i ++) l[i] = -1;
        for(int i = 0; i < m; i ++) r[i] = m;
        while(!st.empty()) st.pop();
        for(int i = 0; i < m; i ++)
        {
            while(!st.empty() && st.top().f > cnt[j][i])
            {
                r[st.top().s] = i;
                st.pop();
            }
            st.push({cnt[j][i], i});
        }
        while(!st.empty()) st.pop();
        for(int i = m-1; i >= 0; i --)
        {
            while(!st.empty() && st.top().f > cnt[j][i])
            {
                l[st.top().s] = i;
                st.pop();
            }
            st.push({cnt[j][i], i});
        }
        for(int i = 0; i < m; i ++)
            ans = max(ans, cnt[j][i] * (r[i] - l[i] - 1));
    }
    cout << ans << "\n";
}
