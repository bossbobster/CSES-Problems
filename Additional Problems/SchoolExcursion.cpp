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
typedef pair<float, float> pff;
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

int curCC = 0;
vector<int> adj[100010];
queue<int> nextInLine;
int cc[100010];
bitset<100010> ans;
vector<int> nums;
int main()
{
    input();
    int n, m, a, b, cur, sz;
    cin >> n >> m;
    for(int i = 0; i < m; i ++)
    {
        cin >> a >> b; a--; b--;
        adj[a].push_back(b); adj[b].push_back(a);
    }
    for(int i = 0; i < n; i ++)
    {
        if(cc[i]) continue;
        curCC ++; sz = 0;
        nextInLine.push(i);
        while(!nextInLine.empty())
        {
            cur = nextInLine.front();
            nextInLine.pop();
            if(cc[cur]) continue;
            cc[cur] = curCC; sz ++;
            for(auto it : adj[cur])
                nextInLine.push(it);
        }
        nums.push_back(sz);
    }
    ans[0] = 1;
    for(auto it : nums)
        ans |= ans<<it;
    for(int i = n-1; i >= 0; i --)
        cout << ans[i];
    cout << '\n';
}
