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
#include <complex>
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
typedef complex<double> cd;
//#define max(n, m) ((n>m)?n:m)
//#define min(n, m) ((n<m)?n:m)
#define f first
#define s second
#define input() ios_base::sync_with_stdio(0);cin.tie(0);

set<int> adj[100010];
int in[100010];
vector<int> ord;
stack<int> st;
int tmp;
int main()
{
    int n, m, a, b, cur;
    cin >> n >> m;
    for(int i = 0; i < m; i ++)
    {
        cin >> a >> b; a--; b--;
        adj[a].insert(b); in[b]++;
    }
    if(adj[0].size() != in[0]+1 || adj[n-1].size() != in[n-1]-1) { cout << "IMPOSSIBLE\n"; return 0; }
    for(int i = 1; i < n-1; i ++)
        if(adj[i].size() != in[i])
        {
            cout << "IMPOSSIBLE\n"; return 0;
        }
    st.push(0);
    while(!st.empty())
    {
        cur = st.top();
        if(adj[cur].empty())
        {
            ord.push_back(cur);
            st.pop();
        }
        else
        {
            tmp = *adj[cur].begin(); adj[cur].erase(tmp);
            st.push(tmp);
        }
    }
    for(int i = 0; i < n; i ++)
        if(adj[i].size() != 0)
        {
            cout << "IMPOSSIBLE\n"; return 0;
        }
    for(int i = (int)ord.size()-1; i >= 0; i --)
        cout << ord[i]+1 << " ";
    cout << "\n";
}
